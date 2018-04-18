#include "loginfoqueryviewmanager.h"
#include "../../context/appcontext.h"

LogInfoQueryViewManager::LogInfoQueryViewManager(QObject *parent):  BaseQueryViewManager(parent)
{
    m_dbManagerPtr = (AppDBManager*)AppContext::get("appDBManager");

}

void LogInfoQueryViewManager::searchLogInfoAll()
{
    SqlQueryModel* pTemp = m_dbManagerPtr->searchLogInfoAll();
    setPModel(pTemp);
    emit pModelChanged(pTemp);
}

void LogInfoQueryViewManager::searchLogInfo(QString date)
{
    SqlQueryModel* pTemp = m_dbManagerPtr->searchLogInfo(date);
    setPModel(pTemp);
    emit pModelChanged(pTemp);
}
