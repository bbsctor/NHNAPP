#ifndef RUNNINGINFOCONTROLLER_H
#define RUNNINGINFOCONTROLLER_H
#include "../appcontroller.h"
#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/home/runninginfodatamodel.h"

class RunningInfoController : public AppController
{
public:
    RunningInfoController();
    enum Option{NO_OP, GET_RUNNINGINFO, INIT};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
    bool validate(const QByteArray &resp);
    static bool isOnMeansure;
private:
    //void updateRunningInfo();
    Option m_currentOption;
    RunningInfoDataModel* m_modelPtr;
};

#endif // RUNNINGINFOCONTROLLER_H
