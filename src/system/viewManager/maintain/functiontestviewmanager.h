#ifndef FUNCTIONTESTVIEWMANAGER_H
#define FUNCTIONTESTVIEWMANAGER_H
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/maintain/functiontestcontroller.h"

class FunctionTestViewManager : public ViewManager
{
    Q_OBJECT
public:
    FunctionTestViewManager();
    Q_INVOKABLE void injectBumbValve();
    Q_INVOKABLE void mixingBumb();
    Q_INVOKABLE void dispelFan();
    Q_INVOKABLE void boxFan();
    Q_INVOKABLE void inWater();
    Q_INVOKABLE void inZero();
    Q_INVOKABLE void inStdSample();
    Q_INVOKABLE void inReagentThree();
    Q_INVOKABLE void inReagentFour();
    Q_INVOKABLE void inReagentFive();
private:
    void init();
    FunctionTestController* m_controllerPtr;
};

#endif // FUNCTIONTESTVIEWMANAGER_H
