#include "meansurecontroldatamodel.h"

MeansureControlDataModel::MeansureControlDataModel(QObject *parent):DataModel(parent)
{

}

QString MeansureControlDataModel::time() const
{
    return m_time;
}

void MeansureControlDataModel::setTime(const QString &time)
{
    m_time = time;
}
