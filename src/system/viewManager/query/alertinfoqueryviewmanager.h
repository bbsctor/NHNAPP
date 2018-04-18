#ifndef ALERTINFOQUERYVIEWMANAGER_H
#define ALERTINFOQUERYVIEWMANAGER_H
#include "basequeryviewmanager.h"

class AlertInfoQueryViewManager : public BaseQueryViewManager
{
    Q_OBJECT
public:
    AlertInfoQueryViewManager(QObject *parent = 0);
    Q_INVOKABLE void searchAlertInfoAll();
    Q_INVOKABLE void searchAlertInfo(QString date);
};

#endif // ALERTINFOQUERYVIEWMANAGER_H
