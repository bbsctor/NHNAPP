#ifndef PARAMETERSETTINGCONTROLLER_H
#define PARAMETERSETTINGCONTROLLER_H
#include "../appcontroller.h"
#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/setting/parametersettingdatamodel.h"
#include "../../dataModel/setting/settingdefaultinformationdatamodel.h"

class ParameterSettingController :public AppController
{
public:
    ParameterSettingController();
    enum Option{NO_OP, GET_SAMPLECONCENTRATION, SET_SAMPLECONCENTRATION,
                INIT,GET_MEGLOCKABLE, SET_MEGLOCKABLE,GET_WASHINGABLE,
                SET_WASHINGABLE, GET_PREHANDLERABLE, SET_PREHANDLERABLE,
                GET_BUMBONTIME, SET_BUMBONTIME, GET_DISPELTIME, SET_DISPELTIME};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
//    bool validate(const QString &resp);
private:
    void readDefaultParameters();
    Option m_currentOption;
//    ParameterSettingDataModel* m_modelPtr;
     SettingDefaultInformationDataModel * m_modelPtr;
};

#endif // PARAMETERSETTINGCONTROLLER_H
