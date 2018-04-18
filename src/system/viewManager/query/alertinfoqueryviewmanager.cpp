#include "alertinfoqueryviewmanager.h"
#include "../../context/appcontext.h"

AlertInfoQueryViewManager::AlertInfoQueryViewManager(QObject *parent):  BaseQueryViewManager(parent)
{
    m_dbManagerPtr = (AppDBManager*)AppContext::get("appDBManager");
}

void AlertInfoQueryViewManager::searchAlertInfoAll()
{
    SqlQueryModel* pTemp = m_dbManagerPtr->searchAlertInfoAll();
    setPModel(pTemp);
    emit pModelChanged(pTemp);
}
void AlertInfoQueryViewManager::searchAlertInfo(QString date)
{
    SqlQueryModel* pTemp = m_dbManagerPtr->searchAlertInfo(date);
    setPModel(pTemp);
    emit pModelChanged(pTemp);
}
