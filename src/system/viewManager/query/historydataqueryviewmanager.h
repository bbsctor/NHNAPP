#ifndef HISTORYDATAQUERYVIEWMANAGER_H
#define HISTORYDATAQUERYVIEWMANAGER_H
#include "../../database/appdbmanager.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "basequeryviewmanager.h"
#include <QtSql>

class HistoryDataQueryViewManager : public BaseQueryViewManager
{
    Q_OBJECT
    //Q_PROPERTY(SqlQueryModel* pModel READ pModel WRITE setPModel NOTIFY pModelChanged)

public:
    HistoryDataQueryViewManager(QObject *parent = 0);
    Q_INVOKABLE void searchMeansureRecordAll();
    Q_INVOKABLE void searchMeansureRecord(QString date);
};

#endif // HISTORYDATAQUERYVIEWMANAGER_H
