#include "historydataqueryviewmanager.h"
#include "../../context/appcontext.h"


HistoryDataQueryViewManager::HistoryDataQueryViewManager(QObject *parent): BaseQueryViewManager(parent)
{
    //m_dbManagerPtr = (AppDBManager*)AppContext::get("appDBManager");
}

void HistoryDataQueryViewManager::searchMeansureRecordAll()
{
    SqlQueryModel* pTemp = m_dbManagerPtr->searchMeansureRecordAll();
    setPModel(pTemp);
    emit pModelChanged(pTemp);
}

void HistoryDataQueryViewManager::searchMeansureRecord(QString date)
{
    SqlQueryModel* pTemp = m_dbManagerPtr->searchMeansureRecord(date);
    setPModel(pTemp);
    emit pModelChanged(pTemp);
}
