#ifndef BASEQUERYVIEWMANAGER_H
#define BASEQUERYVIEWMANAGER_H
#include "../../database/appdbmanager.h"
#include "../../../framework/viewManager/viewmanager.h"
#include <QtSql>

class BaseQueryViewManager : public ViewManager
{
    Q_OBJECT
    Q_PROPERTY(SqlQueryModel* pModel READ pModel WRITE setPModel NOTIFY pModelChanged)


    public:
        BaseQueryViewManager(QObject *parent = 0);
        AppDBManager* m_dbManagerPtr;
        SqlQueryModel* pModel() const
        {
            return m_pModel;
        }
    public slots:
        void setPModel(SqlQueryModel* pModel);
    signals:
        void pModelChanged(SqlQueryModel* pModel);
    private:
        SqlQueryModel* m_pModel;
};

#endif // BASEQUERYVIEWMANAGER_H
