#ifndef CURRENTVALUECONTROLLER_H
#define CURRENTVALUECONTROLLER_H
#include "../appcontroller.h"
#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/home/currentvaluedatamodel.h"

class CurrentValueController : public AppController
{
public:
    CurrentValueController();
    enum Option{NO_OP, GET_CURRENTVALUE, INIT};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
    bool validate(const QByteArray &resp);
private:
    Option m_currentOption;
    CurrentValueDataModel* m_modelPtr;
};

#endif // CURRENTVALUECONTROLLER_H
