#ifndef BCLJZJSETTINGONECONTROLLER_H
#define BCLJZJSETTINGONECONTROLLER_H
#include "../appcontroller.h"
//#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/setting/bcljzjsettingdatamodelone.h"
#include"../../modelProtocolConvert/settingdefaultinformationconverter.h"

class BCLJZJSettingOneController : public AppController
{
public:
    BCLJZJSettingOneController();
    enum Option{NO_OP, GET_MEGLOCKABLE, SET_MEGLOCKABLE, GET_WASHINGABLE, SET_WASHINGABLE, GET_BUMBONTIME, SET_BUMBONTIME,
                GET_PREHANDLERABLE, SET_PREHANDLERABLE, GET_DILUTE, SET_DILUTE, GET_DISPELTIME, SET_DISPELTIME, INIT,
                GET_CALIBRATIONCURVENUMBER,SET_CALIBRATIONCURVENUMBER,SET_SAMPLECONCENTRATION};
    void execute(Option option, QString paras);
    bool handleResponse(const QByteArray &resp);
//    bool validate(const QByteArray &resp);
    void execute(int action, QString paras);
private:
    void readDefaultParameters();
    Option m_currentOption;
    //BCLJZJSettingDataModelOne* m_modelPtr;
    SettingDefaultInformationDataModel * m_modelPtr;
};

#endif // BCLJZJSETTINGONECONTROLLER_H
