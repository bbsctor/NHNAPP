#include "workitem.h"

WorkItem::WorkItem()
{

}

WorkItem::WorkItem(AppController *controllerPtr, int action, QString para)
{
    this->controllerPtr= controllerPtr;
    this->action=action;
    this->para=para;
}

WorkItem::fill(AppController *controllerPtr, int action, QString para)
{
    this->controllerPtr= controllerPtr;
    this->action=action;
    this->para=para;
}
