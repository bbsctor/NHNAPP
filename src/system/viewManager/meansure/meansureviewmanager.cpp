#include "meansureviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"

MeansureViewManager::MeansureViewManager(QObject *parent): ViewManager(parent)
{
    init();
}

void MeansureViewManager::startOnlineMeansure()
{
    qWarning() << "start online meansure!";
    m_controllerPtr->execute(MeansureController::Option::ONLINE_MEANSURE, NULL);
}

void MeansureViewManager::startOfflineMeansure()
{
    qWarning() << "start offline meansure!";
    m_controllerPtr->execute(MeansureController::Option::OFFLINE_MEANSURE, NULL);
}

void MeansureViewManager::init()
{
    //m_modelPtr = (MeansureControlDataModel*)AppContext::get("meansureControlDataModel");
    m_controllerPtr = (MeansureController*)AppContext::get("meansureController");
    if (/*m_modelPtr == NULL ||*/ m_controllerPtr == NULL)
    {
        qWarning() << "MeansureViewManager init failed!";
    }
}
