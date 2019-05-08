#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(m_net, SIGNAL(s_reply(QString)), this, SLOT(net_reply(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_send_b_clicked()
{
    m_net->send_requests();
}

void MainWindow::net_reply(QString text)
{
    QString appendix = "Transaction Id is:  ";
    ui->receive_t->setText(appendix + text);
}

