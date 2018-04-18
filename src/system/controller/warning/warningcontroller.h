#ifndef WARNINGCONTROLLER_H
#define WARNINGCONTROLLER_H
#include "../appcontroller.h"
#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/warning/warningdatamodel.h"

class WarningController : public AppController
{
public:
    WarningController();
    enum Option{NO_OP, GET_WARNINGINFO};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
    bool validate(const QByteArray &resp);
    private:
        Option m_currentOption;
        WarningDataModel* m_modelPtr;
};
#endif // WARNINGCONTROLLER_H
