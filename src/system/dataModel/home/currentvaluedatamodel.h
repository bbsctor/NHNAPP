#ifndef CURRENTVALUEDATAMODEL_H
#define CURRENTVALUEDATAMODEL_H
#include "../../../framework/datamodel.h"

class CurrentValueDataModel : public DataModel
{
public:
    CurrentValueDataModel();
    QString currentValue() const;
    void setCurrentValue(const QString &currentValue);

private:
    QString m_currentValue;
};

#endif // CURRENTVALUEDATAMODEL_H
