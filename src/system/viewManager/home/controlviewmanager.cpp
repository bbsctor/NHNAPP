#include "controlviewmanager.h"
#include "../../context/appcontext.h"

HomeControlViewManager::HomeControlViewManager()
{
    init();
    timer = new QTimer();
    timer->setInterval(10000);
    timer->connect(timer,SIGNAL(timeout()),this,SLOT(updateLoop()));
    timer->start();
}

void HomeControlViewManager::startMonitor()
{
    //pollProxy.startPoll();

}

void HomeControlViewManager::stopMonitor()
{
    //pollProxy.stopPoll();
}

void HomeControlViewManager::urgencyStop()
{
    m_controllerPtr->execute(HomeController::Option::URGENCYSTOP, NULL);
}

void HomeControlViewManager::updateLoop()
{
    m_controllerPtr->updateLoop();
}

void HomeControlViewManager::init()
{
    m_controllerPtr = (HomeController*)AppContext::get("homeController");
    if (m_controllerPtr == NULL)
    {
        qWarning() << "HomeControlViewManager init failed!";
    }
}
