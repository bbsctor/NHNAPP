//#include "executestatusdatamodel.h"

//ExecuteStatusDataModel::ExecuteStatusDataModel()
//{

//}

#include "executestatusdatamodel.h"

ExecuteStatusDataModel::ExecuteStatusDataModel()
{

}

QString ExecuteStatusDataModel::executeStatus() const
{
    return m_executeStatus;
}

void ExecuteStatusDataModel::setExecuteStatus(const QString &executeStatus)
{
    m_executeStatus = executeStatus;
}
