#ifndef PERIODSETTINGCONTROLLER_H
#define PERIODSETTINGCONTROLLER_H
#include "../appcontroller.h"
#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/setting/periodsettingdatamodel.h"
#include"../../dataModel/setting/settingdefaultinformationdatamodel.h"

class PeriodSettingController : public AppController
{
public:
    PeriodSettingController();
    enum Option{NO_OP, GET_MEANSUREMODE, SET_MEANSUREMODE, INIT,SET_MEASUREINTERVAL,SET_CALIBRATIONPERIOD};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
   // bool validate(const QByteArray &resp);
    void init();
private:
    void readDefaultParameters();
    Option m_currentOption;
    SettingDefaultInformationDataModel* m_modelPtr;
    QTimer* meansureTimer;
    QTimer* calibrationTimer;
};

#endif // PERIODSETTINGCONTROLLER_H
