//#ifndef EXECUTESTATUSDATAMODEL_H
//#define EXECUTESTATUSDATAMODEL_H


//class ExecuteStatusDataModel
//{
//public:
//    ExecuteStatusDataModel();
//};

//#endif // EXECUTESTATUSDATAMODEL_H

#ifndef EXECUTESTATUSDATAMODEL_H
#define EXECUTESTATUSDATAMODEL_H
#include <QString>


class ExecuteStatusDataModel
{
public:
    ExecuteStatusDataModel();

    QString executeStatus() const;
    void setExecuteStatus(const QString &executeStatus);

private:
    QString m_executeStatus;
};

#endif // EXECUTESTATUSDATAMODEL_H
