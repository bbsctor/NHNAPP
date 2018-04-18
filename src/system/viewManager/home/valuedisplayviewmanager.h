#ifndef VALUEDISPLAYVIEWMANAGER_H
#define VALUEDISPLAYVIEWMANAGER_H
#include "../../dataModel/home/currentvaluedatamodel.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/home/currentvaluecontroller.h"
#include "../../../framework/observe/qobserver.h"

class ValueDisplayViewManager : public ViewManager,QObserver
{
    Q_OBJECT

    Q_PROPERTY(QString currentValue READ currentValue WRITE setCurrentValue NOTIFY currentValueChanged)
public:
    ValueDisplayViewManager();


    Q_INVOKABLE void pullCurrentValue();
    void Update(QObservable *pObs, void *pArg = NULL);

    QString currentValue() const
    {
        return m_currentValue;
    }

public slots:
    void setCurrentValue(QString currentValue)
    {
        if (m_currentValue == currentValue)
            return;

        m_currentValue = currentValue;
        emit currentValueChanged(currentValue);
    }

signals:


    void currentValueChanged(QString currentValue);

private:
    void init();
    void updateViewCurrentValue(CurrentValueDataModel* pModel);
    CurrentValueDataModel* m_modelPtr;
    CurrentValueController* m_controllerPtr;
    QString m_currentValue;
};

#endif // VALUEDISPLAYVIEWMANAGER_H
