#include "warningconverter.h"

WarningConverter::WarningConverter()
{

}
void WarningConverter::parseWarningInfo(QByteArray byteArray, WarningDataModel *pModel)
{
    //故障代码	0无故障，1比色皿温度异常，2冰箱温度异常，3注射泵异常，4切换阀异常

    int currentWarningStatus = byteArray[2];


    switch(currentWarningStatus)
    {
    case 0:
        pModel->setWarningInfo("无故障");
        break;
    case 1:
        pModel->setWarningInfo("比色皿温度异常！！！");
        break;
    case 2:
        pModel->setWarningInfo("冰箱温度异常！！！");
        break;
    case 3:
        pModel->setWarningInfo("注射泵异常！！！");
        break;
    case 4:
        pModel->setWarningInfo("切换阀异常！！！");
        break;
    case 5:
        pModel->setWarningInfo("浓度异常！！！");
        break;

    }


}
