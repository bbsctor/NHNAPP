#include "communicationserver.h"
#include <QDebug>
//AppController* CommunicationServer::m_handlerPtr;

CommunicationServer::CommunicationServer(QObject *parent) :QObject(parent)
{
    serialport.setPara("COM3",QSerialPort::Baud9600,QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop);
    serialport.openSerial();
}

CommunicationServer::CommunicationServer(const CommunicationServer&){

}


CommunicationServer& CommunicationServer::operator=(const CommunicationServer&){

}


//在此处初始化
CommunicationServer* CommunicationServer::instance = new CommunicationServer();
CommunicationServer* CommunicationServer::getInstance(){
    return instance;
}


int CommunicationServer::sendAndReceive(QByteArray req, QByteArray &resp, AppController *controllerPtr)
{
    //appendItem(new ServerItem(req,resp,controllerPtr));

    int ret =serialport.writeAndRead(req,resp);
    if(ret==0)
    {
       controllerPtr->handleResponse(resp);
    }
    return ret;
}



void CommunicationServer::handleResponse(const QByteArray &s)
{
//    qWarning() <<"receiving data: "<< s;
//    CommunicationServer::m_handlerPtr->handleResponse(s);
}

void CommunicationServer::processError(const QString &s)
{
    //CommunicationServer::m_handlerPtr->handleError(s);
}

void CommunicationServer::processTimeout(const QString &s)
{
    //CommunicationServer::m_handlerPtr->handleTimeout(s);
}

