#ifndef NETWORK_H
#define NETWORK_H

#include <QtNetwork>
#include <QObject>
#include "reply_proccess.h"


class network : public QObject
{
    Q_OBJECT
public:
    explicit network(QObject *parent = nullptr);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QNetworkReply *response;

    reply_proccess *m_rp = new reply_proccess();

    QUrl url;

    bool m_send = false;

    bool m_pay = false;

    void send_requests();

    void payment_con(QString text);

private slots:
    void serviceRequestFinish(QNetworkReply*);

signals:

    void s_reply(QString);
};

#endif // NETWORK_H
