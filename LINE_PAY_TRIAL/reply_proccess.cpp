#include "reply_proccess.h"
#include "QJsonDocument"
#include "QJsonObject"
#include <QDebug>

reply_proccess::reply_proccess(QObject *parent) : QObject(parent)
{

}

QString reply_proccess::Reply_Process(QString text)
{
    QJsonDocument j_d = QJsonDocument::fromJson(text.toUtf8().data());
    if(j_d.isObject()){
        QJsonObject j_o = j_d.object();
        QJsonObject j_o_1 = j_o["info"].toObject();
        QString result  = QString::number(j_o_1["transactionId"].toDouble(), 'f', 0);
        qDebug() << "result:" << result << j_o_1["transactionId"];
        return result;
    }
    else{
        return "Nothing";
    }
}

QString reply_proccess::Reply_transaction(QString text)
{
    QJsonDocument j_d = QJsonDocument::fromJson(text.toUtf8().data());
    if(j_d.isObject()){
        QJsonObject j_o = j_d.object();
        QJsonObject j_o_1 = j_o["info"].toObject();
        QString result  = QString::number(j_o_1["transactionId"].toDouble(), 'f', 0);
        qDebug() << "result:" << result << j_o_1["transactionId"];
        return result;
    }
    else{
        return "Nothing";
    }
}
