#ifndef LOGINFOQUERYVIEWMANAGER_H
#define LOGINFOQUERYVIEWMANAGER_H
#include "basequeryviewmanager.h"

class LogInfoQueryViewManager : public BaseQueryViewManager
{
    Q_OBJECT
public:
    LogInfoQueryViewManager(QObject *parent = 0);
    Q_INVOKABLE void searchLogInfoAll();
    Q_INVOKABLE void searchLogInfo(QString date);
};

#endif // LOGINFOQUERYVIEWMANAGER_H
