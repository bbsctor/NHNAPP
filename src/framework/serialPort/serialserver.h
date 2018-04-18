#ifndef SERIALSERVER_H
#define SERIALSERVER_H

#include <QObject>
#include "masterthread.h"

class SerialServer : public QObject
{
    Q_OBJECT
public:
    explicit SerialServer(QObject *parent = 0);
signals:

public slots:
    void transaction(const QString &portName, int waitTimeout, const QByteArray &request);
    virtual void handleResponse(const QByteArray &s);
    virtual void processError(const QString &s);
    virtual void processTimeout(const QString &s);
private:
    int transactionCount;
    //MasterThread thread;
};

#endif // SERIALSERVER_H
