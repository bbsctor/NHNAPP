#include "currentvaluedatamodel.h"

CurrentValueDataModel::CurrentValueDataModel()
{

}

QString CurrentValueDataModel::currentValue() const
{
    return m_currentValue;
}

void CurrentValueDataModel::setCurrentValue(const QString &currentValue)
{
    m_currentValue = currentValue;
}
