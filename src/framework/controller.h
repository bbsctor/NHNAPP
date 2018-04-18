#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    virtual void send(QByteArray request);
    virtual bool handleResponse(const QByteArray &resp);
    virtual bool handleError(const QString &error);
    virtual bool handleTimeout(const QString &timeout);
    virtual bool validate(const QByteArray &resp);
signals:

public slots:
};

#endif // CONTROLLER_H
