#include "stprotocol2.h"
#include "../../framework/crc/JQChecksum.h"
using namespace JQChecksum;
#include<QDateTime>

STProtocol2::STProtocol2()
{

}
//1	在线测量：00								1	在线测量：00


QByteArray STProtocol2::getOnlineMeansureRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x00;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getOnlineMeansureNormalResponse()
{

}
//1	离线测量：01								1	离线测量：01

QByteArray STProtocol2::getOfflineMeansureRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x01;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getOfflineMeansureNormalResponse()
{

}
//1	磁力锁使能：02	0不使用，1使用							1	磁力锁使能：02	0不使用，1使用

QByteArray STProtocol2::getMegLockAbleRequest(char isEnable)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x02;
    ba[2] = isEnable;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getMegLockAbleNormalResponse()
{

}
//1	自来水冲洗使能：03	0不使能，1使能							1	自来水冲洗使能：03	0不使能，1使能

QByteArray STProtocol2::getWashingAbleRequest(char isEnable)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x03;
    ba[2] = isEnable;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getWashingAbleNormalResponse()
{

}
//1	采样泵启动时间：04	分钟数							1	采样泵启动时间：04	分钟数

QByteArray STProtocol2::getSettingBumbOnTimeRequest(char minute)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x04;
    ba[2] = minute;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getSettingBumbOnTimeNormalResponse()
{

}
//1	预处理器冲洗使能：05	0不使能，1使能							1	预处理器冲洗使能：05	0不使能，1使能
QByteArray STProtocol2::getPreHandlerWashingAbleRequest(char isEnable)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x05;
    ba[2] = isEnable;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getPreHandlerWashingAbleNormalResponse()
{

}
//1	稀释倍数：06	倍数的高8位	倍数的低8位						1	稀释倍数：06	倍数的高8位	倍数的低8位
QByteArray STProtocol2::getSettingDiluteRequest(char high, char low)
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x06;
    ba[2] = high;
    ba[3] = low;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

//QByteArray STProtocol2::getSettingDiluteNormalResponse()
//{

//}
//1	消解时间：07	分钟数							1	消解时间：07	分钟数
QByteArray STProtocol2::getSettingDispelTimeRequest(char minute)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x07;
    ba[2] = minute;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getSettingDispelTimeNormalResponse()
{

}


////1	时间设置01	年	月	日	时	分	秒					1	时间设置01



//QByteArray STProtocol2::getSettingTimeRequest(char year, char month, char day, char hour, char minute, char second)
//{
//    QByteArray ba;
//    ba.resize(8);
//    ba[0] = 0x01;
//    ba[1] = 0x01;
//    ba[2] = year;
//    ba[3] = month;
//    ba[4] = day;
//    ba[5] = hour;
//    ba[6] = minute;
//    ba[7] = second;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingTimeNormalResponse()
//{

//}
////1	报警设置02	报警开关	报警上限	报警上限	报警上限	报警上限	报警下限	报警下限	报警下限	报警下限		1	报警设置02

//QByteArray STProtocol2::getSettingAlarmRequest(char on, char up, char down)
//{
//    QByteArray ba;
//    ba.resize(11);
//    ba[0] = 0x01;
//    ba[1] = 0x02;
//    ba[2] = on;
//    ba[3] = up;
//    ba[4] = up;
//    ba[5] = up;
//    ba[6] = up;
//    ba[7] = down;
//    ba[8] = down;
//    ba[9] = down;
//    ba[10] = down;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingAlarmNormalResponse()
//{

//}
////1	预启设置03	预启时间										1	预启设置03

//QByteArray STProtocol2::getSettingPreStartTimeRequest(char time)
//{
//    QByteArray ba;
//    ba.resize(3);
//    ba[0] = 0x01;
//    ba[1] = 0x03;
//    ba[2] = time;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingPreStartTimeNormalResponse()
//{

//}
////1	标1设置04	标1浓度	标1浓度	标1浓度	标1浓度							1	标1设置04

//QByteArray STProtocol2::getSettingStdOneRequest(char std1)
//{
//    QByteArray ba;
//    ba.resize(6);
//    ba[0] = 0x01;
//    ba[1] = 0x04;
//    ba[2] = std1;
//    ba[3] = std1;
//    ba[4] = std1;
//    ba[5] = std1;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}


//QByteArray STProtocol2::getSettingStdOneNormalResponse()
//{

//}
////1	标2设置05	标2浓度	标2浓度	标2浓度	标2浓度							1	标2设置05
//QByteArray STProtocol2::getSettingStdTwoRequest(char std2)
//{
//    QByteArray ba;
//    ba.resize(6);
//    ba[0] = 0x01;
//    ba[1] = 0x05;
//    ba[2] = std2;
//    ba[3] = std2;
//    ba[4] = std2;
//    ba[5] = std2;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingStdTwoNormalResponse()
//{

//}
////1	标3设置06	标3浓度	标3浓度	标3浓度	标3浓度							1	标3设置06

//QByteArray STProtocol2::getSettingStdThreeRequest(char std3)
//{
//    QByteArray ba;
//    ba.resize(6);
//    ba[0] = 0x01;
//    ba[1] = 0x06;
//    ba[2] = std3;
//    ba[3] = std3;
//    ba[4] = std3;
//    ba[5] = std3;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingStdThreeNormalResponse()
//{

//}
////1	量程温度时间设置07	量程	温度	消解时间								1	量程温度时间设置07

//QByteArray STProtocol2::getSettingSpanTempTimeRequest(char span, char temp, char time)
//{
//    QByteArray ba;
//    ba.resize(5);
//    ba[0] = 0x01;
//    ba[1] = 0x07;
//    ba[2] = span;
//    ba[3] = temp;
//    ba[4] = time;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingSpanTempTimNormalResponse()
//{

//}
////1	周期设置08	校准周期	校准时间	清洗周期	清洗时间							1	周期设置08

//QByteArray STProtocol2::getSettingPeroidRequest(char calPeroid, char calTime, char washPeroid, char washTime)
//{
//    QByteArray ba;
//    ba.resize(6);
//    ba[0] = 0x01;
//    ba[1] = 0x08;
//    ba[2] = calPeroid;
//    ba[3] = calTime;
//    ba[4] = washPeroid;
//    ba[5] = washTime;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingPeroidNormalResponse()
//{

//}
////1	自动间隔测量模式 09	自动测量间隔										1	自动间隔测量模式09

//QByteArray STProtocol2::getSettingAutoIntervalMeansureModeRequest()
//{
//     QByteArray ba;
//     ba.resize(2);
//     ba[0] = 0x01;
//     ba[1] = 0x09;
//     JQChecksum::appendCrc16ForModbus(ba);

//     return ba;
//}

//QByteArray STProtocol2::getSettingAutoIntervalMeansureModeNormalResponse()
//{
//    QByteArray ba;
//    ba.resize(2);
//    ba[0] = 0x01;
//    ba[1] = 0x09;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}
////1	整点测量间隔 10	0-7点（对应位置1）	8-15点（对应位置1）	16-23点（对应位置1）								1	整点测量间隔10

//QByteArray STProtocol2::getSettingClockIntervalMeansureModeRequest()
//{
//    QByteArray ba;
//    ba.resize(2);
//    ba[0] = 0x01;
//    ba[1] = 0x09;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingClockIntervalMeansureModeNormalResponse()
//{
//    QByteArray ba;
//    ba.resize(2);
//    ba[0] = 0x01;
//    ba[1] = 0x09;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}
////1	手动测量模式 11											1	手动测量模式11

//QByteArray STProtocol2::getSettingManualMeansureModeRequest()
//{
//    QByteArray ba;
//    ba.resize(2);
//    ba[0] = 0x01;
//    ba[1] = 0x11;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

//QByteArray STProtocol2::getSettingManualMeansureModeNormalResponse()
//{
//    QByteArray ba;
//    ba.resize(2);
//    ba[0] = 0x01;
//    ba[1] = 0x11;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}
//1	维护：测量22											1	维护：测量22

QByteArray STProtocol2::getMeansureModeRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x22;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getMeansureModeNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x22;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：校准23											1	维护：校准23

QByteArray STProtocol2::getCalibrationRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x23;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getCalibrationNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x23;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：初始化24											1	维护：初始化24

QByteArray STProtocol2::getInitialRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x24;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getInitialNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x24;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：除气泡25											1	维护：除气泡25

QByteArray STProtocol2::getCleanBubbleRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x25;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getCleanBubbleNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x25;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：清洗比色皿26											1	维护：清洗比色皿26

QByteArray STProtocol2::getWashCuvetteRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x26;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getWashCuvetteNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x26;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：试剂清洗比色皿27											1	维护：试剂清洗比色皿27

QByteArray STProtocol2::getReagentWashCuvetteRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x27;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getReagentWashCuvetteNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x27;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：结束处理28											1	维护：结束处理28

QByteArray STProtocol2::getFinishDisposeRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x28;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getFinishDisposeNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x28;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：零点检测29											1	维护：零点检测29

QByteArray STProtocol2::getZeroMeansureRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x29;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getZeroMeansureNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x29;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：紧急停止30											1	维护：紧急停止30

QByteArray STProtocol2::getUrgencyStopRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x30;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getUrgencyStopNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x30;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//	维护：查询状态31												维护：查询状态31	当前状态

QByteArray STProtocol2::getSearchStatusRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x31;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getSearchStatusNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x31;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：零点校准32											1	维护：零点校准32

QByteArray STProtocol2::getZeroCalibrationRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x32;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getZeroCalibrationNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x32;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	维护：量程校准33											1	维护：量程校准33

QByteArray STProtocol2::getSpanCalibrationRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x33;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getSpanCalibrationNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x33;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：注射泵与十通阀测试36											1	测试：注射泵与十通阀测试36

QByteArray STProtocol2::getInjectBumbValveRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x36;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getInjectBumbValveNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x36;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：搅拌泵测试37											1	测试：搅拌泵测试37

QByteArray STProtocol2::getMixingBumbRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x37;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getMixingBumbNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x37;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：消解管风扇测试38											1	测试：消解管风扇测试38

QByteArray STProtocol2::getDispelFanRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x38;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getDispelFanNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x38;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：机柜风扇测试39											1	测试：机柜风扇测试39

QByteArray STProtocol2::getBoxFanRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x39;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getBoxFanNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x39;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：进水样40											1	测试：进水样40

QByteArray STProtocol2::getInWaterRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x40;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getInWaterNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x40;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：进零样41											1	测试：进零样41

QByteArray STProtocol2::getInZeroRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x41;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getInZeroNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x41;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：进标样42											1	测试：进标样42

QByteArray STProtocol2::getInStdSampleRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x42;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getInStdSampleNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x42;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：进试剂3 43											1	测试：进试剂3 43

QByteArray STProtocol2::getInReagentThreeRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x43;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getInReagentThreeNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x43;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：进试剂4 44											1	测试：进试剂4 44

QByteArray STProtocol2::getInReagentFourRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x44;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getInReagentFourNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x44;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	测试：进试剂5 45											1	测试：进试剂5 45

QByteArray STProtocol2::getInReagentFiveRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x45;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getInReagentFiveNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x45;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	系统信息46											1	系统信息46	电子签名共12字节	………

QByteArray STProtocol2::getManufactureInfoRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x46;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getManufactureInfoNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x46;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//1	查询当前状态47 											1	查询当前状态47 	当前状态	当前动作	后续动作	当前消解池温度	当前环境温度	吸光度	吸光度	吸光度	吸光度	进度

QByteArray STProtocol2::getRunningInfoRequest()
{
    QDateTime dt=QDateTime::currentDateTime();
    int year1=(int)(dt.date().year());
    char year2=(char)(year1%2000);
    char month1=(char)(dt.date().month());
    char day1=(char)(dt.date().day());
    char hour1=(char)(dt.time().hour());
    char minute1=(char)(dt.time().minute());
    char second1=(char)(dt.time().second());

    QByteArray ba;
    ba.resize(8);
    ba[0] = 0x01;
    ba[1] = 0x47;
//    for(int i=0;i<6;i++)
//    {
//        ba[i+2]=(char)i;
//    }
    ba[2]=year2;
    ba[3]=month1;
    ba[4]=day1;

    ba[5]=hour1;
    ba[6]=minute1;
    ba[7]=second1;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getRunningInfoInfoNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x47;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}
//    1	查询当前浓度48											1	查询当前浓度48	浓度值	浓度值（注：浓度值为整数，且为实际的100倍）
QByteArray STProtocol2::getCurrentMeansureValueRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x48;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getCurrentMeansureValueNormalResponse()
{

}

//    1	确认接收到的校正系数k，b49

QByteArray STProtocol2::getCalibrationCoefRequest(int n)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x49;
    ba[2] = (char)n;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;

}
//QByteArray STProtocol2::getCalibrationCoefRequest()
//{
//    QByteArray ba;
//    ba.resize(2);
//    ba[0] = 0x01;
//    ba[1] = 0x49;
//    JQChecksum::appendCrc16ForModbus(ba);

//    return ba;
//}

QByteArray STProtocol2::getCalibrationCoefNormalResponse()
{

}

//动作代码	1 水样前预处理，2 蠕动泵采样，3 测量前管路清洗，4水样稀释，5 抽取试剂，6 消解管消解 ，7 比色测量 ，8测量后管路清洗
//状态代码	1在线测量，2离线测量，3零点校准 4 标准液校准
//错误代码	0x00状态正常，0x01帧错误  0x02 参数错误  0x03 光耦错误 0x04 电机忙 0xfe任务挂起 0xff 未知错误
//    1	查询当前浓度48											1	查询当前浓度48	浓度值	浓度值（注：浓度值为整数，且为实际的100倍）


//校准曲线选择50
//[2017:10:11:16:44:46][发送]01 50 03 5C 01
//[2017:10:11:16:44:46][接收]01 50 03 5C 01
//数据第3位03表示选择第三条校准曲线

QByteArray STProtocol2::getSettingCalibrationCurveNumberRequest(int n)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x50;
    ba[2] = (char)n;
    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol2::getSettingCalibrationCurveNumberNormalRespone()
{

}






//查询报警 51
QByteArray STProtocol2::getWarningInfoRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x51;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getWarningInfoInfoNormalResponse()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x51;
    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}




//1	标样浓度：06
QByteArray STProtocol2::getSettingSampleConsentrationRequest(int i)
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x06;
    ba[2] =(char)(i/256);
    ba[3] = (char)(i % 256);

    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getSettingSampleConcentrationNormalResponse()
{

}

//1	报警上下线：52
QByteArray STProtocol2::getAlertUpperLowZoneRequest(int upper,int low)
{
    QByteArray ba;
    ba.resize(6);
    ba[0] = 0x01;
    ba[1] = 0x52;
    ba[2] =(char)(upper/256);
    ba[3] = (char)(upper % 256);
    ba[4]=(char)(low/256);
    ba[5] = (char)(low % 256);

    JQChecksum::appendCrc16ForModbus(ba);

    return ba;
}

QByteArray STProtocol2::getAlertUpperLowZoneNormalResponse()
{

}

//485通讯使能
QByteArray STProtocol2::getRS485AbleRequest(char isEnable)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x53;
    ba[2] = isEnable;
    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol2::getRS485AbleNormalResponse()
{

}

//4到20mA通讯使能
QByteArray STProtocol2::get4to20mAAbleRequest(char isEnable)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x01;
    ba[1] = 0x54;
    ba[2] = isEnable;
    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol2::ge4to20mAAbleNormalResponse()
{

}

//    查询系统设置
QByteArray STProtocol2::getSystemSettingDefaultInfoRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x55;
    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
QByteArray STProtocol2::getSystemSettingDefaultInfoNormalResponse()
{

}

    //    查询参数设置
QByteArray STProtocol2::getParameterSettingDefaultInfoRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x56;
    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
QByteArray STProtocol2::getParameterSettingDefaultInfoNormalResponse()
{

}

//    查询周期设置
QByteArray STProtocol2::getPeriodSettingDefaultInfoRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x57;
    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
QByteArray STProtocol2::getPeriodSettingDefaultInfoNormalResponse()
{

}

//    查询标样浓度设置
QByteArray STProtocol2::getCalibrationSettingDefaultInfoRequest()
{
    QByteArray ba;
    ba.resize(2);
    ba[0] = 0x01;
    ba[1] = 0x58;
    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
QByteArray STProtocol2::getCalibrationSettingDefaultInfoNormalResponse()
{

}


//    测量模式设置
//    [2017:10:11:16:44:46][发送] 01 59 00 1A 50
//    [2017:10:11:16:44:46][接收]  01 59 00 1A 50
//    数据第3表示测量模式，0表示自动，1表示手动
    QByteArray STProtocol2::getSettingMeasureModeRequest(char mode)
    {
        QByteArray ba;
        ba.resize(3);
        ba[0] = 0x01;
        ba[1] = 0x59;
        ba[2]=mode;
        JQChecksum::appendCrc16ForModbus(ba);
        return ba;
    }
    QByteArray  STProtocol2::getSettingMeasureModeNomalRespsonse()
    {

    }

//    校准周期设置
//    [2017:10:11:16:44:46][发送] 01 60 00 08 00
//    [2017:10:11:16:44:46][接收] 01 60 00 08 00
//    数据第3表示校准周期时间，无符号整数
   QByteArray  STProtocol2::getSettingCalibrationgPeriodRequest(char period)
    {
        QByteArray ba;
        ba.resize(3);
        ba[0] = 0x01;
        ba[1] = 0x60;
        ba[2]=period;
        JQChecksum::appendCrc16ForModbus(ba);
        return ba;
    }

    QByteArray  STProtocol2::getSettingCalibrationgPeriodNomalRespsonse()
    {

    }

//    测量间隔设置
//    [2017:10:11:16:44:46][发送] 01 61 00 09 90
//    [2017:10:11:16:44:46][接收] 01 61 00 09 90
//    数据第3表示测量时间，无符号整数
   QByteArray  STProtocol2::getSettingMeasureIntervalRequest(char interval)
    {
        QByteArray ba;
        ba.resize(3);
        ba[0] = 0x01;
        ba[1] = 0x61;
        ba[2]=interval;
        JQChecksum::appendCrc16ForModbus(ba);
        return ba;
    }
   QByteArray  STProtocol2::getSettingMeasureIntervalNomalRespsonse()
    {

    }

//获取校准曲线

   QByteArray  STProtocol2::getSelectedCurveRequest()
    {
        QByteArray ba;
        ba.resize(2);
        ba[0] = 0x01;
        ba[1] = 0x62;

        JQChecksum::appendCrc16ForModbus(ba);
        return ba;
    }

    QByteArray  STProtocol2::getSelectedCurveNomalRespsonse()
    {

    }

    //   从站地址设置
    //   [2017:10:11:16:44:46][发送] 01 63 01 C9 30
    //   [2017:10:11:16:44:46][接收] 01 63 01 C9 30
    //   数据第3表示从站地址，无符号整数（1-31）
    QByteArray  STProtocol2::getSettingSlaveAddressRequest(char slaveAddress)
     {
         QByteArray ba;
         ba.resize(3);
         ba[0] = 0x01;
         ba[1] = 0x63;
         ba[2]= slaveAddress;
         JQChecksum::appendCrc16ForModbus(ba);
         return ba;
     }

     QByteArray  STProtocol2::getSettingSlaveAddressNomalRespsonse()
     {

     }
