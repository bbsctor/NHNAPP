#include "meansurecontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../context/appcontext.h"

#include <QDebug>
#include<QDateTime>

MeansureController::MeansureController()
{
    AppContext::set("autoMeansureTimer",new QTimer(this));
    meansureTimer = (QTimer*)AppContext::get("autoMeansureTimer");
    meansureTimer->connect(meansureTimer,SIGNAL(timeout()),this,SLOT(meansureWrapper()));
}

void MeansureController::execute(MeansureController::Option option, QString paras = NULL)
{
    WorkItem item;
        switch(option)
        {
            case Option::ONLINE_MEANSURE:
                 item.fill(this, 0, paras);
                pollProxy->addWork(item);
                break;
            case Option::OFFLINE_MEANSURE:
                item.fill(this, 1, paras);
                pollProxy->addWork(item);
                break;
        }
}

void MeansureController::execute(int option, QString paras = NULL)
{
    QByteArray request=NULL;
        switch(option)
        {
            case 0:
                exeViewManger->setExecuteStatus("在线测量指令下发！");
                dbManager->insertLogInfo("在线测量指令下发！");
                request=STProtocol2::getOnlineMeansureRequest();
                 m_currentOption = Option::ONLINE_MEANSURE;

                break;
            case 1:
                exeViewManger->setExecuteStatus("离线测量指令下发！");
                dbManager->insertLogInfo("离线测量指令下发！");
                request=STProtocol2::getOfflineMeansureRequest();
                 m_currentOption = Option::OFFLINE_MEANSURE;
                break;
        }

        send(request);
}



bool MeansureController::handleResponse(const QByteArray &resp)
{
    if(Controller::handleResponse(resp) == true)
    {
        switch(m_currentOption)
        {
        case Option::ONLINE_MEANSURE:
            AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("在线测量指令下发成功！");
            dbManager->insertLogInfo("在线测量指令下发成功！");
            break;
        case Option::OFFLINE_MEANSURE:
            AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("离线测量指令下发成功！");
            dbManager->insertLogInfo("离线测量指令下发成功！");
            break;
        }
    }
    else
    {

    }
}

bool MeansureController::validate(const QByteArray &resp)
{
    return true;
}

void MeansureController::autoMeansureOn(int interval)
{

    if(meansureTimer->interval() != interval)
    {
        meansureTimer->setInterval(interval);
        exeViewManger->setExecuteStatus("重置测量间隔成功！");
        dbManager->insertLogInfo("重置测量间隔成功！");
    }
    if(meansureTimer->isActive() == false)
    {
        meansureTimer->start();
        exeViewManger->setExecuteStatus("启动自动测量成功！");
        dbManager->insertLogInfo("启动自动测量成功！");
    }
    QString temp = "下次自动测量时间：";
    QDateTime dt = QDateTime::currentDateTime().addMSecs(meansureTimer->interval());
    temp.append(dt.toString("yyyy.MM.dd hh:mm:ss"));
    exeViewManger->setAutoMeansure(temp);
}

void MeansureController::autoMeansureOff()
{
    if(meansureTimer->isActive() == true)
    {
        meansureTimer->stop();
    }
    exeViewManger->setAutoMeansure("");
}

void MeansureController::meansureWrapper()
{
    execute(MeansureController::Option::ONLINE_MEANSURE, NULL);
    QString temp = "下次自动测量时间：";
    QDateTime dt = QDateTime::currentDateTime().addMSecs(meansureTimer->interval());
    temp.append(dt.toString("yyyy.MM.dd hh:mm:ss"));
    exeViewManger->setAutoMeansure(temp);
}
