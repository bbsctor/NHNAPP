#include "basequeryviewmanager.h"
#include "../../context/appcontext.h"

BaseQueryViewManager::BaseQueryViewManager(QObject *parent): ViewManager(parent)
{
    m_dbManagerPtr = (AppDBManager*)AppContext::get("appDBManager");
}

void BaseQueryViewManager::setPModel(SqlQueryModel *pModel)
{
    if (m_pModel == pModel)
        return;

    m_pModel = pModel;
    emit pModelChanged(pModel);
}
