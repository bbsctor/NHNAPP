#ifndef MEANSUREDATAMODEL_H
#define MEANSUREDATAMODEL_H
#include "../../framework/datamodel.h"

class MeansureControlDataModel : public DataModel
{
    //Q_OBJECT
public:
    explicit MeansureControlDataModel(QObject *parent = 0);
    QString time() const;
    void setTime(const QString &time);

private:
    QString m_time;
};

#endif // MEANSUREDATAMODEL_H
