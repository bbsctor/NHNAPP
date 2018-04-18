#include "controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::send(QByteArray request)
{

}

bool Controller::handleResponse(const QByteArray &resp)
{
    qWarning() << "receive response!";
    if (validate(resp) == true)
    {
        return true;
    }
    else
    {
        qWarning() << "response error!";
        return false;
    }
}

bool Controller::handleError(const QString &error)
{
    return true;
}

bool Controller::handleTimeout(const QString &timeout)
{
    qWarning() << "controller handle Timeout!" + timeout;
    return true;
}

bool Controller::validate(const QByteArray &resp)
{
    qWarning() << "no validate!";
    return true;
}

