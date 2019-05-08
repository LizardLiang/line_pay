#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "network.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void net_reply(QString);

private slots:
    void on_send_b_clicked();

private:
    Ui::MainWindow *ui;

    network *m_net = new network();
};

#endif // MAINWINDOW_H
