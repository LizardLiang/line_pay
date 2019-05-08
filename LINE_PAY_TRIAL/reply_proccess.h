#ifndef REPLY_PROCCESS_H
#define REPLY_PROCCESS_H

#include <QObject>

class reply_proccess : public QObject
{
    Q_OBJECT
public:
    explicit reply_proccess(QObject *parent = nullptr);

    QString Reply_Process(QString);

    QString Reply_transaction(QString);

signals:

public slots:
};

#endif // REPLY_PROCCESS_H
