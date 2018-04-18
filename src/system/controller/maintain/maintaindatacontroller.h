#ifndef MAINTAINDATACONTROLLER_H
#define MAINTAINDATACONTROLLER_H
#include "../appcontroller.h"
//#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/maintain/calibrationcoefdatamodel.h"

class MaintainDataController : public AppController
{
public:
    MaintainDataController();
    enum Option{NO_OP, GET_CALIBRATIONCOEF};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
//    bool validate(const QByteArray &resp);
    private:
        Option m_currentOption;
        MaintainDataDataModel* m_modelPtr;
};

#endif // MAINTAINDATACONTROLLER_H
