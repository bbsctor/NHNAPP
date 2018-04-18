#include "appcontroller.h"
#include "../communication/communicationserver.h"
#include "../context/appcontext.h"
#include "../dataModel/status/executestatusdatamodel.h"
#include "../communication/serveritem.h"
int AppController::reCount=0;
AppController::AppController()
{
    dbManager = (AppDBManager*)AppContext::get("appDBManager");
    pollProxy = PollProxy::getInstance();
}

void AppController::execute(int action, QString paras)
{

}

void AppController::send(QByteArray request)
{
    QString temp = QString::number(request[1]);
    temp.append("功能码指令发送失败！");
    int ret = 0;
    QMutex mutex;
    mutex.lock();
    ret = CommunicationServer::getInstance()->sendAndReceive(request,m_resp,this);
    mutex.unlock();
    if(ret != 0)
    {
        dbManager->insertLogInfo(temp);
    }

}

bool AppController::validateResponse(const QByteArray &req, const QByteArray &resp)
{
    return true;
}

bool AppController::handleResponse(const QByteArray &resp)
{
    return true;
}

bool AppController::handleTimeout(const QString &timeout)
{
    exeViewManger->setExecuteStatus("响应超时!");
     if(reCount < 3)
     {
         send(lastSendData);
         reCount++;
     }
     else
     {
         reCount = 0;
     }
     return true;
}

bool AppController::registerExeViewManger(ExecuteViewManager* viewManger)
{
    exeViewManger = viewManger;
    return true;
}
