#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    QTextDocument *doc = ui->textEdit->document();
    QString s = doc->toPlainText();
    ui->textEdit->setPlainText(s + "hoge");
}
