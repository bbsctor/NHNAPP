#include "appdbmanager.h"
#include <QDebug>
#include "../dataModel/home/currentvaluedatamodel.h"
#include "../context/appcontext.h"
#include "../controller/meansure/meansurecontroller.h"
#include "../controller/home/currentvaluecontroller.h"

AppDBManager::AppDBManager(QObject *parent) : DBManager(parent)
{
    m_historyDataDBHelperPtr = new HistoryDataDBHelper();
    m_historyDataDBHelperPtr->createTable();

    m_alertInfoDBHelperPtr = new AlertInfoDBHelper();
    m_alertInfoDBHelperPtr->createTable();

    m_logInfoDBHelperPtr = new LogInfoDBHelper();
    m_logInfoDBHelperPtr->createTable();
}

void AppDBManager::Update(QObservable *pObs, void *pArg)
{
    CurrentValueDataModel* pContent = static_cast<CurrentValueDataModel*>(pArg);
    // 观察目标
    if(dynamic_cast <CurrentValueController*>(pObs))
    {
        m_historyDataDBHelperPtr->insert("20170822", pContent->currentValue());
    }
}

void AppDBManager::insertHistoryData(CurrentValueDataModel* pContent)
{
        m_historyDataDBHelperPtr->insert("20170822", pContent->currentValue());
}

SqlQueryModel* AppDBManager::searchMeansureRecordAll()
{
    return m_historyDataDBHelperPtr->searchAll();
}
SqlQueryModel* AppDBManager::searchMeansureRecord(QString date)
{
    return m_historyDataDBHelperPtr->search(date);
}

SqlQueryModel *AppDBManager::searchAlertInfoAll()
{
    return m_alertInfoDBHelperPtr->searchAll();
}
SqlQueryModel *AppDBManager::searchAlertInfo(QString date)
{
    return m_alertInfoDBHelperPtr->search(date);
}

SqlQueryModel *AppDBManager::searchLogInfoAll()
{
    return m_logInfoDBHelperPtr->searchAll();
}
SqlQueryModel *AppDBManager::searchLogInfo(QString date)
{
    return m_logInfoDBHelperPtr->search(date);
}

void AppDBManager::insertLogInfo(QString str)
{
    m_logInfoDBHelperPtr->insert("20170822", str);
}

void AppDBManager::insertAlertInfo(QString str)
{
    m_alertInfoDBHelperPtr->insert("20170822", str);
}
