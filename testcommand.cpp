#include "testcommand.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QtCore/QDebug>

TestCommand::TestCommand()
{
}

QString TestCommand::getCommand() {
    QJsonObject jHead, jPayload, jObj;
    jHead["test1"] = "0";
    jHead["test2"] = 1;
    jPayload["test3"] = "1";
    jPayload["test4"] = 2;

    jObj["head"] = jHead;
    jObj["payload"] = jPayload;

    qDebug() << jObj ;

    QJsonDocument doc(jObj);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    return strJson;
}

void TestCommand::view()
{
    QJsonObject jHead, jPayload, jObj;
    jHead["test1"] = "0";
    jHead["test2"] = 1;
    jPayload["test3"] = "1";
    jPayload["test4"] = 2;

    jObj["head"] = jHead;
    jObj["payload"] = jPayload;

    qDebug() << jObj ;
}


