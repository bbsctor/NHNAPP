#ifndef FUNCTIONTESTCONTROLLER_H
#define FUNCTIONTESTCONTROLLER_H
#include "../appcontroller.h"

class FunctionTestController : public AppController
{
public:
    FunctionTestController();
//    enum Option{NO_OP, IN_WATERSAMPLE, IN_ZEROSAMPLE, IN_STDONE, IN_STDTWO, IN_TESTONE, IN_TESTTWO, BUBBLE, HEATER,
//                INITFILL, WASH_MEANSURETUBE, WASH_DISPELJAR ,INIT};
    enum Option{NO_OP, INJECTBUMBVALVE, MIXINGBUMB, DISPELFAN, BOXFAN, INWATER, INZERO, INSTDSAMPLE, INREAGENTTHREE, INREAGENTFOUR, INREAGENTFIVE};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
    bool validate(const QByteArray &resp);
    private:
        Option m_currentOption;
};

#endif // FUNCTIONTESTCONTROLLER_H
