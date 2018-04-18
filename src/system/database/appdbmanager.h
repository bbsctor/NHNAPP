#ifndef APPDBMANAGER_H
#define APPDBMANAGER_H
#include "../../framework/observe/qobserver.h"
#include "historydatadbhelper.h"
#include "alertinfodbhelper.h"
#include "loginfodbhelper.h"
#include "../../framework/database/dbmanager.h"
#include "../dataModel/home/currentvaluedatamodel.h"

class AppDBManager : public DBManager,QObserver
{
public:
    explicit AppDBManager(QObject *parent = 0);
    void Update(QObservable *pObs, void *pArg = NULL);
    void insertHistoryData(CurrentValueDataModel* pContent);
    void insertLogInfo(QString str);
    void insertAlertInfo(QString str);
    SqlQueryModel* searchMeansureRecordAll();
    SqlQueryModel *searchAlertInfoAll();
    SqlQueryModel *searchLogInfoAll();
    HistoryDataDBHelper* m_historyDataDBHelperPtr;
    AlertInfoDBHelper* m_alertInfoDBHelperPtr;
    LogInfoDBHelper* m_logInfoDBHelperPtr;

    SqlQueryModel* searchMeansureRecord(QString date);
    SqlQueryModel *searchAlertInfo(QString date);
    SqlQueryModel *searchLogInfo(QString date);
};

#endif // APPDBMANAGER_H
