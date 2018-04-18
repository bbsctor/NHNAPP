#include "serialserver.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

SerialServer::SerialServer(QObject *parent) : QObject(parent),
    transactionCount(0)
{
    const auto infos = QSerialPortInfo::availablePorts();
//    connect(&thread, &MasterThread::response, this, &SerialServer::handleResponse);
//    connect(&thread, &MasterThread::error, this, &SerialServer::processError);
//    connect(&thread, &MasterThread::timeout, this, &SerialServer::processTimeout);
}


void SerialServer::transaction(const QString &portName, int waitTimeout, const QByteArray &request)
{
    qWarning() <<"sending data: "<< request;
   // thread.transaction(portName,waitTimeout,request);
}

void SerialServer::handleResponse(const QByteArray &s)
{
    qWarning() << "receive!" + s.toHex();
}

void SerialServer::processError(const QString &s)
{

}

void SerialServer::processTimeout(const QString &s)
{
    qWarning() << "timeout!" + s;

}
