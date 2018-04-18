#ifndef SERVERITEM_H
#define SERVERITEM_H
#include "../controller/appcontroller.h"
#include <QObject>
class ServerItem
{
    //Q_OBJECT
public:
    ServerItem();
    AppController* controllerPtr;
    QByteArray req;
    QByteArray resp;


//    ServerItem& operator=(const ServerItem&);
//    bool  operator==(const ServerItem& item);
};

#endif // SERVERITEM_H
