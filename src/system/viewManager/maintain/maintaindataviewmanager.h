#ifndef MAINTAINDATAVIEWMANAGER_H
#define MAINTAINDATAVIEWMANAGER_H
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/maintain/maintaindatacontroller.h"

class MaintainDataViewManager : public ViewManager,QObserver
{
    Q_OBJECT
    //Q_PROPERTY(QString calibrationCoefK READ calibrationCoefK WRITE setCalibrationCoefK NOTIFY calibrationCoefKChanged)
    //Q_PROPERTY(QString calibrationCoefB READ calibrationCoefB WRITE setCalibrationCoefB NOTIFY calibrationCoefBChanged)
    Q_PROPERTY(QString calibrationCoefK1 READ calibrationCoefK1 WRITE setCalibrationCoefK1 NOTIFY calibrationCoefK1Changed)
    Q_PROPERTY(QString calibrationCoefB1 READ calibrationCoefB1 WRITE setCalibrationCoefB1 NOTIFY calibrationCoefB1Changed)
    Q_PROPERTY(QString calibrationCoefK2 READ calibrationCoefK2 WRITE setCalibrationCoefK2 NOTIFY calibrationCoefK2Changed)
    Q_PROPERTY(QString calibrationCoefB2 READ calibrationCoefB2 WRITE setCalibrationCoefB2 NOTIFY calibrationCoefB2Changed)
    Q_PROPERTY(QString calibrationCoefK3 READ calibrationCoefK3 WRITE setCalibrationCoefK3 NOTIFY calibrationCoefK3Changed)
    Q_PROPERTY(QString calibrationCoefB3 READ calibrationCoefB3 WRITE setCalibrationCoefB3 NOTIFY calibrationCoefB3Changed)
    Q_PROPERTY(QString calibrationCoefK4 READ calibrationCoefK4 WRITE setCalibrationCoefK4 NOTIFY calibrationCoefK4Changed)
    Q_PROPERTY(QString calibrationCoefB4 READ calibrationCoefB4 WRITE setCalibrationCoefB4 NOTIFY calibrationCoefB4Changed)
    Q_PROPERTY(QString calibrationCoefK5 READ calibrationCoefK5 WRITE setCalibrationCoefK5 NOTIFY calibrationCoefK5Changed)
    Q_PROPERTY(QString calibrationCoefB5 READ calibrationCoefB5 WRITE setCalibrationCoefB5 NOTIFY calibrationCoefB5Changed)

public:
    MaintainDataViewManager();
    //QString calibrationCoefK() const;
    //QString calibrationCoefB() const;
    void Update(QObservable *pObs, void *pArg = NULL);
    Q_INVOKABLE void pullCalibrationCoef();


    QString calibrationCoefK1() const;
    void setCalibrationCoefK1(const QString &calibrationCoefK1);

    QString calibrationCoefB1() const;
    void setCalibrationCoefB1(const QString &calibrationCoefB1);

    QString calibrationCoefK2() const;
    void setCalibrationCoefK2(const QString &calibrationCoefK2);

    QString calibrationCoefB2() const;
    void setCalibrationCoefB2(const QString &calibrationCoefB2);

    QString calibrationCoefK3() const;
    void setCalibrationCoefK3(const QString &calibrationCoefK3);

    QString calibrationCoefB3() const;
    void setCalibrationCoefB3(const QString &calibrationCoefB3);

    QString calibrationCoefK4() const;
    void setCalibrationCoefK4(const QString &calibrationCoefK4);

    QString calibrationCoefB4() const;
    void setCalibrationCoefB4(const QString &calibrationCoefB4);

    QString calibrationCoefK5() const;
    void setCalibrationCoefK5(const QString &calibrationCoefK5);

    QString calibrationCoefB5() const;
    void setCalibrationCoefB5(const QString &calibrationCoefB5);

public slots:
    //void setCalibrationCoefK(QString calibrationCoefK);

    //void setCalibrationCoefB(QString calibrationCoefB);

    void getCoef();
    //void getCoef(QString i);

signals:
    //void calibrationCoefKChanged(QString calibrationCoefK);
    //void calibrationCoefBChanged(QString calibrationCoefB);
    void calibrationCoefK1Changed(QString calibrationCoefK1);

    void calibrationCoefB1Changed(QString calibrationCoefB1);

    void calibrationCoefK2Changed(QString calibrationCoefK2);

    void calibrationCoefB2Changed(QString calibrationCoefB2);

    void calibrationCoefK3Changed(QString calibrationCoefK3);

    void calibrationCoefB3Changed(QString calibrationCoefB3);

    void calibrationCoefK4Changed(QString calibrationCoefK4);

    void calibrationCoefB4Changed(QString calibrationCoefB4);

    void calibrationCoefK5Changed(QString calibrationCoefK5);

    void calibrationCoefB5Changed(QString calibrationCoefB5);

private:
    void init();
    void updateViewCalibrationCoef(MaintainDataDataModel* modelPtr);

    MaintainDataController* m_controllerPtr;
    MaintainDataDataModel* m_modelPtr;
    QString m_calibrationCoefK1;
    QString m_calibrationCoefB1;
    QString m_calibrationCoefK2;
    QString m_calibrationCoefB2;
    QString m_calibrationCoefK3;
    QString m_calibrationCoefB3;
    QString m_calibrationCoefK4;
    QString m_calibrationCoefB4;
    QString m_calibrationCoefK5;
    QString m_calibrationCoefB5;

   static  int  i;
};

#endif // MAINTAINDATAVIEWMANAGER_H
