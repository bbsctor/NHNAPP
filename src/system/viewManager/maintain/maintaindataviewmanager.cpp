#include "maintaindataviewmanager.h"
#include <QDebug>
#include <QThread>
#include <QTimer>
#include "../../context/appcontext.h"
#include "../../controller/maintain/maintaindatacontroller.h"
#include <typeinfo>



MaintainDataViewManager::MaintainDataViewManager()
{
    MaintainDataController* cptr = (MaintainDataController*)AppContext::get("maintainDataController");
    cptr->Attach(this);
    init();
}

int  MaintainDataViewManager::i = 0;
QString temp;
//QTimer *t1;
void MaintainDataViewManager::pullCalibrationCoef()
{
//    QTimer t1=new QTimer(this);
//    t1->connect(t1, SIGNAL(timeout()), this, SLOT(getCoef()));
//    t1->start(1000);
    temp = "2";
    m_controllerPtr->execute(MaintainDataController::Option::GET_CALIBRATIONCOEF, "1");
    QTimer::singleShot(2000, this, SLOT(getCoef()));
    QTimer::singleShot(4000, this,SLOT(getCoef()));
    QTimer::singleShot(6000, this,SLOT(getCoef()));
    QTimer::singleShot(8000, this,SLOT(getCoef()));

}

void MaintainDataViewManager::getCoef()
{
//   if( i == 0)
//   {
//      temp = QString::number(i + 1);
//   }

   m_controllerPtr->execute(MaintainDataController::Option::GET_CALIBRATIONCOEF, temp);
   if(temp.compare("2") == 0)
   {
       temp = "3";
   }
   else if(temp.compare("3") == 0)
   {
       temp = "4";
   }
   else if(temp.compare("4") == 0)
   {
       temp = "5";
   }
   else if(temp.compare("5") == 0)
   {
       temp = "1";
   }
//   if(i < 5)
//   {
//       temp = QString::number(i + 1);
//       i++;
//   }
//   else
//   {
//       i = 0;
//      // t1->stop();
//   }
}

void MaintainDataViewManager::updateViewCalibrationCoef(MaintainDataDataModel* modelPtr)
{
//    MaintainDataViewManager::setCalibrationCoefK(modelPtr->coefK());
//    MaintainDataViewManager::setCalibrationCoefB(modelPtr->coefB());
    MaintainDataViewManager::setCalibrationCoefB1(modelPtr->coefB1());
    MaintainDataViewManager::setCalibrationCoefB2(modelPtr->coefB2());
    MaintainDataViewManager::setCalibrationCoefB3(modelPtr->coefB3());
    MaintainDataViewManager::setCalibrationCoefB4(modelPtr->coefB4());
    MaintainDataViewManager::setCalibrationCoefB5(modelPtr->coefB5());
    MaintainDataViewManager::setCalibrationCoefK1(modelPtr->coefK1());
    MaintainDataViewManager::setCalibrationCoefK2(modelPtr->coefK2());
    MaintainDataViewManager::setCalibrationCoefK3(modelPtr->coefK3());
    MaintainDataViewManager::setCalibrationCoefK4(modelPtr->coefK4());
    MaintainDataViewManager::setCalibrationCoefK5(modelPtr->coefK5());
}

QString MaintainDataViewManager::calibrationCoefB5() const
{
    return m_calibrationCoefB5;
}

void MaintainDataViewManager::setCalibrationCoefB5(const QString &calibrationCoefB5)
{
    if (m_calibrationCoefB5 == calibrationCoefB5)
        return;

    m_calibrationCoefB5 = calibrationCoefB5;
    emit calibrationCoefB5Changed(calibrationCoefB5);
}

QString MaintainDataViewManager::calibrationCoefK5() const
{
    return m_calibrationCoefK5;
}

void MaintainDataViewManager::setCalibrationCoefK5(const QString &calibrationCoefK5)
{
    if (m_calibrationCoefK5 == calibrationCoefK5)
        return;

    m_calibrationCoefK5 = calibrationCoefK5;
    emit calibrationCoefK5Changed(calibrationCoefK5);
}

QString MaintainDataViewManager::calibrationCoefB4() const
{
    return m_calibrationCoefB4;
}

void MaintainDataViewManager::setCalibrationCoefB4(const QString &calibrationCoefB4)
{
    if (m_calibrationCoefB4 == calibrationCoefB4)
        return;

    m_calibrationCoefB4 = calibrationCoefB4;
    emit calibrationCoefB4Changed(calibrationCoefB4);
}

QString MaintainDataViewManager::calibrationCoefK4() const
{
    return m_calibrationCoefK4;
}

void MaintainDataViewManager::setCalibrationCoefK4(const QString &calibrationCoefK4)
{
    if (m_calibrationCoefK4 == calibrationCoefK4)
        return;

    m_calibrationCoefK4 = calibrationCoefK4;
    emit calibrationCoefK4Changed(calibrationCoefK4);
}

QString MaintainDataViewManager::calibrationCoefB3() const
{
    return m_calibrationCoefB3;
}

void MaintainDataViewManager::setCalibrationCoefB3(const QString &calibrationCoefB3)
{
    if (m_calibrationCoefB3 == calibrationCoefB3)
        return;

    m_calibrationCoefB3 = calibrationCoefB3;
    emit calibrationCoefB3Changed(calibrationCoefB3);
}

QString MaintainDataViewManager::calibrationCoefK3() const
{
    return m_calibrationCoefK3;
}

void MaintainDataViewManager::setCalibrationCoefK3(const QString &calibrationCoefK3)
{
    if (m_calibrationCoefK3 == calibrationCoefK3)
        return;

    m_calibrationCoefK3 = calibrationCoefK3;
    emit calibrationCoefK3Changed(calibrationCoefK3);
}

QString MaintainDataViewManager::calibrationCoefB2() const
{
    return m_calibrationCoefB2;
}

void MaintainDataViewManager::setCalibrationCoefB2(const QString &calibrationCoefB2)
{
    if (m_calibrationCoefB2 == calibrationCoefB2)
        return;

    m_calibrationCoefB2 = calibrationCoefB2;
    emit calibrationCoefB2Changed(calibrationCoefB2);
}

QString MaintainDataViewManager::calibrationCoefK2() const
{
    return m_calibrationCoefK2;
}

void MaintainDataViewManager::setCalibrationCoefK2(const QString &calibrationCoefK2)
{
    if (m_calibrationCoefK2 == calibrationCoefK2)
        return;

    m_calibrationCoefK2 = calibrationCoefK2;
    emit calibrationCoefK2Changed(calibrationCoefK2);
}

QString MaintainDataViewManager::calibrationCoefB1() const
{
    return m_calibrationCoefB1;
}

void MaintainDataViewManager::setCalibrationCoefB1(const QString &calibrationCoefB1)
{
    if (m_calibrationCoefB1 == calibrationCoefB1)
        return;

    m_calibrationCoefB1 = calibrationCoefB1;
    emit calibrationCoefB1Changed(calibrationCoefB1);
}

QString MaintainDataViewManager::calibrationCoefK1() const
{
    return m_calibrationCoefK1;
}

void MaintainDataViewManager::setCalibrationCoefK1(const QString &calibrationCoefK1)
{
    if (m_calibrationCoefK1 == calibrationCoefK1)
        return;

    m_calibrationCoefK1 = calibrationCoefK1;
    emit calibrationCoefK1Changed(calibrationCoefK1);
}

void MaintainDataViewManager::Update(QObservable *pObs, void *pArg)
{
    MaintainDataDataModel* pContent = static_cast<MaintainDataDataModel*>(pArg);
    // 观察目标
    if(dynamic_cast <MaintainDataController*>(pObs))
        {
            updateViewCalibrationCoef(pContent);
        }
        else
        {

        }
}

void MaintainDataViewManager::init()
{
    m_modelPtr = (MaintainDataDataModel*)AppContext::get("maintainDataDataModel");
    m_controllerPtr = (MaintainDataController*)AppContext::get("maintainDataController");
    if (m_modelPtr == NULL || m_controllerPtr == NULL)
    {
        qWarning() << "MaintainDataViewManager init failed!";
    }
}


