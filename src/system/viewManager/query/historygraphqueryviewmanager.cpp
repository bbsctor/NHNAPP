#include "historygraphqueryviewmanager.h"
#include "../../context/appcontext.h"
#include <QtCore/QDateTime>

HistoryGraphQueryViewManager::HistoryGraphQueryViewManager(QObject *parent): HistoryDataQueryViewManager(parent)
{
    m_dbManagerPtr = (AppDBManager*)AppContext::get("appDBManager");
}

//void HistoryGraphQueryViewManager::getBackData()
//{
//    SqlQueryModel* pTemp = m_dbManagerPtr->searchMeansureRecord();
//    QSqlRecord record;
//    QDateTime momentInTime;
//    int rowCount = pTemp->rowCount();
//    for(int i = 0; i < rowCount; i++)
//    {
//        record=pTemp->record(i);

//        momentInTime = QDateTime::fromString(record.value(0).value<QString>(), "yyyy.MM.dd hh:mm:ss");

//        m_xValues.append(momentInTime.toMSecsSinceEpoch());
//        //m_xValues.append(momentInTime);
//        m_yValues.append(record.value(1));
//    }
//}

//ZN 11-16更改
void HistoryGraphQueryViewManager::getBackData()
{
//    SqlQueryModel* pTemp = m_dbManagerPtr->searchMeansureRecord();
//    QSqlRecord record;
//    QDateTime momentInTime;
//    int rowCount = pTemp->rowCount();
//    for(int i = 0; i < rowCount; i++)
//    {
//        record=pTemp->record(i);

//        momentInTime = QDateTime::fromString(record.value(0).value<QString>(), "yyyy.MM.dd hh:mm:ss");

//        m_xValues.append(momentInTime.toMSecsSinceEpoch());
//        //m_xValues.append(momentInTime);
//        m_yValues.append(record.value(1));
//    }
}
