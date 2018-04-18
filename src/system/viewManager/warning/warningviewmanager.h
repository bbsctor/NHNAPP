#ifndef WARNINGVIEWMANAGER_H
#define WARNINGVIEWMANAGER_H
#include "../../dataModel/warning/warningdatamodel.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/warning/warningcontroller.h"
#include "../../../framework/observe/qobserver.h"

class WarningViewManager: public ViewManager,QObserver
{
    Q_OBJECT

    Q_PROPERTY(QString currentWarningValue READ currentWarningValue WRITE setCurrentWarningValue NOTIFY currentWarningValueChanged)
public:
    WarningViewManager();


    Q_INVOKABLE void pullCurrentWarningValue();
    void Update(QObservable *pObs, void *pArg = NULL);

    QString currentWarningValue() const
    {
        return m_currentWarningValue;
    }

public slots:
    void setCurrentWarningValue(QString currentWarningValue)
    {
        if (m_currentWarningValue == currentWarningValue)
            return;

        m_currentWarningValue = currentWarningValue;
        emit currentWarningValueChanged(currentWarningValue);
    }

signals:


    void currentWarningValueChanged(QString currentWarningValue);

private:
    void init();
    void updateViewCurrentWarningValue(WarningDataModel* pModel);
    WarningDataModel* m_modelPtr;
    WarningController* m_controllerPtr;
    QString m_currentWarningValue;
};

#endif // WARNINGVIEWMANAGER_H
