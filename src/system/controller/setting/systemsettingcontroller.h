#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H
#include "../appcontroller.h"
//#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/setting/systemsettingdatamodel.h"
#include "../../dataModel/setting/settingdefaultinformationdatamodel.h"

class SystemSettingController : public AppController
{
public:
    SystemSettingController();
    enum Option{NO_OP, GET_DEVICEDATETIME, SET_DEVICEDATETIME, INIT,SET_ALEATUPPERLOWZONE,SET_4TO20MAABLE,SET_RS485ABLE,SET_SLAVEADDRESS};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
//    bool validate(const QByteArray &resp);
private:
    void readDefaultParameters();
    Option m_currentOption;
    SettingDefaultInformationDataModel * m_modelPtr;
};

#endif // SYSTEMCONTROLLER_H
