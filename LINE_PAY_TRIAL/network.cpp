#include "network.h"
#include <QDebug>
#include <QJsonObject>
#include <QObject>

network::network(QObject *parent) : QObject(parent)
{
    url = QUrl("https://sandbox-api-pay.line.me/v2/payments/request");
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(serviceRequestFinish(QNetworkReply*)));
    qDebug() << "url" << url;
}

void network::send_requests()
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setRawHeader("X-LINE-ChannelId" , "1565636751");
    request.setRawHeader("X-LINE-ChannelSecret" , "ee5be7577106c99b79a12c657b32b112");

    QJsonObject json;
    json.insert("amount", 100);
    json.insert("productName", "Test");
    json.insert("confirmUrl", "192.168.0.0");
    json.insert("orderId", "2019042200000");
    json.insert("currency", "TWD");
    json.insert("payType", "PREAPPROVED");
    QByteArray json_b = QJsonDocument(json).toJson();
    m_send = true;
    m_pay = true;
    manager->post(request, json_b);
}

void network::serviceRequestFinish(QNetworkReply *reply)
{
    if(m_send){
        QString t_reply = static_cast<QString>(reply->readAll());
        m_send = false;
        if(m_pay){
            QString transactionId = m_rp->Reply_transaction(t_reply);
            payment_con(transactionId);
        }
        else{
            QString t_reply_1 = m_rp->Reply_Process(t_reply);
            emit s_reply(t_reply);
        }
    }
}

void network::payment_con(QString text)
{
    QString temp = "https://sandbox-api-pay.line.me/v2/payments/" + text +
            "/confirm";
    QUrl url_1(temp);
    QNetworkRequest request(url_1);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setRawHeader("X-LINE-ChannelId" , "1565636751");
    request.setRawHeader("X-LINE-ChannelSecret" , "ee5be7577106c99b79a12c657b32b112");

    QJsonObject json;
    json.insert("amount", 100);
    json.insert("currency", "TWD");
    QByteArray json_b = QJsonDocument(json).toJson();
    m_send = true;
    m_pay = false;
    manager->post(request, json_b);
}
