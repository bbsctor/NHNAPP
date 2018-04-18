#ifndef POLLPROXY_H
#define POLLPROXY_H
#include <QTimer>
#include "workitem.h"
class WorkItem;
class PollProxy : public QObject
{
Q_OBJECT
public:

    void startPoll();
    void stopPoll();
    addWork(WorkItem item);
    //int getWork(WorkItem& item);
    QList<WorkItem> workList;
    static PollProxy* getInstance();


    //void updateCurrentValue();
public slots:
    void currentWork();
private:
    PollProxy();
    static PollProxy* instance;
    QTimer *timer;

};

#endif // POLLPROXY_H
