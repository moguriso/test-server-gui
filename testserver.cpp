#include "testserver.h"
#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QTextEdit>
#include <QtCore/QDebug>
#include <QtCore/QFile>

TestServer::TestServer(quint16 port, QTextEdit *textEdit, QObject *parent) :
    QObject(parent),
    m_pWebSocketServer(Q_NULLPTR)
{
    m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Test Server"),
                                              QWebSocketServer::NonSecureMode,
                                              this);
    if (m_pWebSocketServer->listen(QHostAddress::Any, port))
    {
        qDebug() << "Echo Server listening on port " << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &TestServer::onNewConnection);
    }
    if (textEdit) {
        m_pTextEdit = textEdit;
    }
}

TestServer::~TestServer()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void TestServer::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    pSocket->setParent(this);

    connect(pSocket, &QWebSocket::textMessageReceived, this, &TestServer::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &TestServer::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &TestServer::socketDisconnected);

    m_clients << pSocket;

    for (QWebSocket *pClient : qAsConst(m_clients)) {
        pClient->sendTextMessage("abcdefghijkllm");
    }
}

void TestServer::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        pClient->sendTextMessage(message);
    }
    if (this->m_pTextEdit)
    {
        QTextDocument *doc = m_pTextEdit->document();
        QString s = doc->toPlainText();
        m_pTextEdit->setPlainText(s + message);
    }
}

void TestServer::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        pClient->sendBinaryMessage(message);
    }
}

void TestServer::socketDisconnected()
{
    qDebug() << "Client disconnected";
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
