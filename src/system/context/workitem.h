#ifndef WORKITEM_H
#define WORKITEM_H
#include "../controller/appcontroller.h"
class AppController;
class WorkItem
{
public:
    WorkItem();
    WorkItem(AppController* controllerPtr, int action, QString para);
    fill(AppController* controllerPtr, int action, QString para);
    AppController* controllerPtr;
    int action;
    QString para;
};

#endif // WORKITEM_H
