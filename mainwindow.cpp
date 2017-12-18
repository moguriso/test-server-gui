#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testcommand.h"
#include <QtCore/QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->pWsServer = new TestServer(1234, this->ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clearButton_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_sendButton_clicked()
{
    TestCommand tst;
    QString str = tst.getCommand();
    if (pWsServer->SendText(str) == false) {
        qDebug() << "send failed";
    }
}
