#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H
#include "../../framework/controller.h"
#include "../../framework/observe/qobservable.h"
#include "../../system/viewManager/status/executeviewmanager.h"
#include "../database/appdbmanager.h"
#include <QMutex>
#include "../../system/context/workitem.h"
#include "../../system/context/pollproxy.h"
class ExecuteViewManager;
class PollProxy;
class AppController : public Controller, public QObservable
{
public:
    AppController();
    void send(QByteArray request);
    bool handleResponse(const QByteArray &resp);
    bool handleTimeout(const QString &timeout);
    bool registerExeViewManger(ExecuteViewManager* viewManger);
    static bool validateResponse(const QByteArray &req, const QByteArray &resp);
    virtual void execute(int action, QString paras);
    static int reCount;
    QByteArray lastSendData;
    ExecuteViewManager*  exeViewManger;
    AppDBManager* dbManager;
    PollProxy* pollProxy;
    //QMutex mutex;
protected:
    QByteArray req;
    QByteArray m_resp;
};

#endif // APPCONTROLLER_H
