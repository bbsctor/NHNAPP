#include "runninginfoconverter.h"

RunningInfoConverter::RunningInfoConverter()
{

}

ushort RunningInfoConverter::bytesToUint(QByteArray bytes) {
    ushort addr = bytes[1] & 0x000000FF;
    addr |= ((bytes[0] << 8) & 0x0000FF00);
   //uint addr |= ((bytes[1] << 16) & 0x00FF0000);
   // addr |= ((bytes[0] << 24) & 0xFF000000);
    return addr;
}

void RunningInfoConverter::parseRunningInfo(QByteArray byteArray, RunningInfoDataModel *pModel)
{
//old    1	查询当前状态35 	1	查询当前状态35 	当前状态	当前动作	后续动作	当前消解池温度	当前环境温度	吸光度	吸光度	吸光度	吸光度	进度
//new    查询当前状态47 	当前状态	当前动作	后续动作	当前消解池温度	当前环境温度	吸光度1（为实际值的10000倍，有符号整数）	吸光度1	吸光度2	吸光度2	进度	注射泵状态	切换阀状态	冰箱char


//    动作代码	1 水样前预处理，2 蠕动泵采样，3 测量前管路清洗，4水样稀释，5 抽取试剂，6 消解管消解 ，7 比色测量 ，8测量后管路清洗，9结束	10 空闲状态
//    状态代码	状态代码	0空闲状态，1在线测量，2离线测量，3零点校准 4 标准液校准		 5 初始化	6 除气泡	7 清洗比色皿		8 试剂清洗比色皿	9 结束处理	10 零点检测
//    11 紧急停止	12 注射泵与十通阀测试	13搅拌泵测试	14 消解管风扇测试		15 机柜风扇测试		16 进水样	17 进零样
//	  16 进标样	17 进试剂3	18 进试剂4	19 进试剂5

//    错误代码	0x00状态正常，0x01帧错误  0x02 参数错误  0x03 光耦错误 0x04 电机忙 0xfe任务挂起 0xff 未知错误								

//    0x00注射泵状态正常，0x01注射泵帧错误  0x02 注射泵参数错误  0x03 注射泵光耦错误 0x04 注射泵电机忙 0xfe注射泵挂起 0xff 注射泵未知错误
//    0x00切换阀正常，0x01切换阀帧错误  0x02 切换阀参数错误  0x03 切换阀光耦错误  0x04切换阀电机忙  0xfe切换阀挂起  0xff 切换阀未知错误
    QByteArray array;
    array.resize(2);
    if(byteArray.size() <  15)
          return;
    array[0] = byteArray[9];
    array[1] = byteArray[10];

    int currentStatus = byteArray[2];
    int currentAction = byteArray[3];
    int nextAction = byteArray[4];
    uchar dispelTemperature = byteArray[5];
    uchar environmentTemperature = byteArray[6];
    //uchar absorbance = byteArray[9];
    //ushort absorbance = byteArray[9] * 256 + byteArray[10];
    ushort absorbance =bytesToUint(array);
    uchar progress = byteArray[11];
    int injectBumbStatus = byteArray[12];
    int switchValvoStatus = byteArray[13];
    int coolerTemperature = byteArray[14];

    switch(switchValvoStatus)
    {
        case 0:
            pModel->setSwitchValvoStatus("切换阀正常");
            break;
        case 1:
            pModel->setSwitchValvoStatus("切换阀帧错误");
            break;
        case 2:
            pModel->setSwitchValvoStatus("切换阀参数错误");
            break;
        case 3:
            pModel->setSwitchValvoStatus("切换阀光耦错误");
            break;
        case 4:
            pModel->setSwitchValvoStatus("切换阀电机忙");
            break;
        case 254:
            pModel->setSwitchValvoStatus("切换阀挂起");
            break;
        case 255:
            pModel->setSwitchValvoStatus("切换阀未知错误");
            break;
    }

    switch(injectBumbStatus)
    {
        case 0:
            pModel->setInjectBumbStatus("注射泵状态正常");
            break;
        case 1:
            pModel->setInjectBumbStatus("注射泵帧错误");
            break;
        case 2:
            pModel->setInjectBumbStatus("注射泵参数错误");
            break;
        case 3:
            pModel->setInjectBumbStatus("注射泵光耦错误");
            break;
        case 4:
            pModel->setInjectBumbStatus("注射泵电机忙");
            break;
        case 254:
            pModel->setInjectBumbStatus("注射泵挂起");
            break;
        case 255:
            pModel->setInjectBumbStatus("注射泵未知错误");
            break;
    }

    switch(currentStatus)
    {
        case 0x00:
            pModel->setCurrentStatus("空闲状态");
            break;
        case 0x01:
            pModel->setCurrentStatus("在线测量");
            break;
        case 0x02:
            pModel->setCurrentStatus("离线测量");
            break;
        case 0x03:
            pModel->setCurrentStatus("零点校准");
            break;
        case 0x04:
            pModel->setCurrentStatus("标准液校准");
            break;
        case 0x05:
            pModel->setCurrentStatus("初始化");
            break;
        case 0x06:
            pModel->setCurrentStatus("除气泡");
            break;
        case 0x07:
            pModel->setCurrentStatus("清洗比色皿");
            break;
        case 0x08:
            pModel->setCurrentStatus("试剂清洗比色皿");
            break;
        case 0x09:
            pModel->setCurrentStatus("结束处理");
            break;
        case 0x10:
            pModel->setCurrentStatus("零点检测");
            break;
        case 0x11:
            pModel->setCurrentStatus("紧急停止");
            break;
        case 0x12:
            pModel->setCurrentStatus("注射泵与十通阀测试");
            break;
        case 0x13:
            pModel->setCurrentStatus("搅拌泵测试");
            break;
        case 0x14:
            pModel->setCurrentStatus("消解管风扇测试");
            break;
        case 0x15:
            pModel->setCurrentStatus("机柜风扇测试");
            break;
        case 0x16:
            pModel->setCurrentStatus("进水样");
            break;
        case 0x17:
            pModel->setCurrentStatus("进零样");
            break;
        case 0x18:
            pModel->setCurrentStatus("进标样");
            break;
        case 0x19:
            pModel->setCurrentStatus("进试剂3");
            break;
        case 0x20:
            pModel->setCurrentStatus("进试剂4");
            break;
        case 0x21:
            pModel->setCurrentStatus("进试剂4");
            break;
    }

    switch(nextAction)
    {
        case 1:
            pModel->setNextAction("水样前预处理");
            break;
        case 2:
            pModel->setNextAction("蠕动泵采样");
            break;
        case 3:
            pModel->setNextAction("测量前管路清洗");
            break;
        case 4:
            pModel->setNextAction("水样稀释");
            break;
        case 5:
            pModel->setNextAction("抽取试剂");
            break;
        case 6:
            pModel->setNextAction("消解管消解");
            break;
        case 7:
            pModel->setNextAction("比色测量");
            break;
        case 8:
            pModel->setNextAction("测量后管路清洗");
            break;
        case 9:
            pModel->setNextAction("结束");
            break;
        case 0x10:
            pModel->setNextAction("空闲状态");
            break;
        }

        switch(currentAction)
        {
            case 1:
                pModel->setCurrentAction("水样前预处理");
                break;
            case 2:
                pModel->setCurrentAction("蠕动泵采样");
                break;
            case 3:
                pModel->setCurrentAction("测量前管路清洗");
                break;
            case 4:
                pModel->setCurrentAction("水样稀释");
                break;
            case 5:
                pModel->setCurrentAction("抽取试剂");
                break;
            case 6:
                pModel->setCurrentAction("消解管消解");
                break;
            case 7:
                pModel->setCurrentAction("比色测量");
                break;
            case 8:
                pModel->setCurrentAction("测量后管路清洗");
                break;
            case 9:
                pModel->setCurrentAction("结束");
                break;
            case 0x10:
                pModel->setCurrentAction("空闲状态");
                break;
        }

    pModel->setDispelTemperature(QString::number(dispelTemperature)+"℃");
    pModel->setEnvironmentTemperature(QString::number(environmentTemperature)+"℃");
    double realValue = (double)absorbance / 1000;
    pModel->setAbsorbance(QString::number(realValue, 10 , 3));
    pModel->setProgress(progress);
    pModel->setCoolerTempearture(QString::number(coolerTemperature)+"℃");
}
