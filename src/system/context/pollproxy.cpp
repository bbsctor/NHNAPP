#include "pollproxy.h"
#include "../context/appcontext.h"

#include"../controller/warning/warningcontroller.h"
#include <QDebug>
PollProxy* PollProxy::instance = NULL;
PollProxy::PollProxy()
{
    timer = new QTimer(this);
}

void PollProxy::startPoll()
{
    if(timer == NULL)
        timer = new QTimer(this);

    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(currentWork()));
    timer->start(2000);
}

void PollProxy::stopPoll()
{
    timer->stop();
}

PollProxy::addWork(WorkItem item)
{
    workList.append(item);
}

PollProxy *PollProxy::getInstance()
{
        if(PollProxy::instance == NULL)
        {
            instance = new PollProxy();
        }
        return instance;
}

void PollProxy::currentWork()
{
    if(workList.size() > 0)
    {
            WorkItem item = workList.takeFirst();
            item.controllerPtr->execute(item.action, item.para);
    }
}
