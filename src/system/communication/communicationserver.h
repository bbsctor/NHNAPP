#ifndef COMMUNICATIONSERVER_H
#define COMMUNICATIONSERVER_H
#include <QObject>
#include "../../framework/serialPort/serialserver.h"
#include "../controller/appcontroller.h"

#include "operateserialport.h"

class CommunicationServer : public QObject
{
public:
    static CommunicationServer* getInstance();
    void handleResponse(const QByteArray &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);
    //static AppController* m_handlerPtr;

     int sendAndReceive(QByteArray req, QByteArray &resp,AppController* controllerPtr);
private:
    CommunicationServer(QObject *parent = 0);
        //把复制构造函数和=操作符也设为私有,防止被复制
    CommunicationServer(const CommunicationServer&);
    CommunicationServer& operator=(const CommunicationServer&);

    static CommunicationServer* instance;


    Operateserialport serialport;

};

#endif // COMMUNICATIONSERVER_H



//#ifndef COMMUNICATIONSERVER_H
//#define COMMUNICATIONSERVER_H
//#include <QObject>
//#include "../../framework/serialPort/serialserver.h"
//#include "../controller/appcontroller.h"
//#include "serveritem.h"

////class CommunicationServer : public SerialServer
//class CommunicationServer : public QObject
//{
//    Q_OBJECT
//public:
//    static CommunicationServer* getInstance();
////    void handleResponse(const QByteArray &s);
////    void processError(const QString &s);
////    void processTimeout(const QString &s);
//    void send(ServerItem item);
//    ServerItem getone();
//    //static AppController* m_handlerPtr;

////    QList<ServerItem> & itemList()
////    {
////        return &list;
////    }

//    QList<ServerItem> list;
//    QMutex mutex;

//private:
//    CommunicationServer();
//        //把复制构造函数和=操作符也设为私有,防止被复制
//    CommunicationServer(const CommunicationServer&);
//    CommunicationServer& operator=(const CommunicationServer&);

//    static CommunicationServer* instance;



//};

//#endif // COMMUNICATIONSERVER_H
