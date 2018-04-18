#ifndef MANUFACTUREINFOCONTROLLER_H
#define MANUFACTUREINFOCONTROLLER_H
#include "../appcontroller.h"
//#include "../../../framework/observe/qobservable.h"
#include "../../dataModel/query/manufactureinfodatamodel.h"

class ManufactureInfoController : public AppController
{
public:
    ManufactureInfoController();
    enum Option{NO_OP, GET_INFO};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
    bool validate(const QByteArray &resp);
private:
    void updateManufactureInfo();
    Option m_currentOption;
    ManufactureInfoDataModel* m_modelPtr;
};

#endif // MANUFACTUREINFOCONTROLLER_H
