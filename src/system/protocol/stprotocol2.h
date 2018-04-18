#ifndef STPROTOCOL2_H
#define STPROTOCOL2_H
#include "../../framework/protocoldef.h"

class STProtocol2 : public ProtocolDef
{
public:
    STProtocol2();

    //    地址码	功能码	数据	数据	数据	数据	数据	数据	数据	数据	数据		地址码	功能码

    //    1	在线测量：00								1	在线测量：00
    static QByteArray getOnlineMeansureRequest();
    static QByteArray getOnlineMeansureNormalResponse();
    //    1	离线测量：01								1	离线测量：01
    static QByteArray getOfflineMeansureRequest();
    static QByteArray getOfflineMeansureNormalResponse();
    //    1	磁力锁使能：02	0不使用，1使用							1	磁力锁使能：02	0不使用，1使用
    static QByteArray getMegLockAbleRequest(char isEnable);
    static QByteArray getMegLockAbleNormalResponse();
    //    1	自来水冲洗使能：03	0不使能，1使能							1	自来水冲洗使能：03	0不使能，1使能
    static QByteArray getWashingAbleRequest(char isEnable);
    static QByteArray getWashingAbleNormalResponse();
    //    1	采样泵启动时间：04	分钟数							1	采样泵启动时间：04	分钟数
    static QByteArray getSettingBumbOnTimeRequest(char minute);
    static QByteArray getSettingBumbOnTimeNormalResponse();
    //    1	预处理器冲洗使能：05	0不使能，1使能							1	预处理器冲洗使能：05	0不使能，1使能
    static QByteArray getPreHandlerWashingAbleRequest(char isEnable);
    static QByteArray getPreHandlerWashingAbleNormalResponse();
    //    1	稀释倍数：06	倍数的高8位	倍数的低8位						1	稀释倍数：06	倍数的高8位	倍数的低8位
    static QByteArray getSettingDiluteRequest(char high, char low);
    static QByteArray getSettingDiluteNormalResponse();
    //    1	消解时间：07	分钟数							1	消解时间：07	分钟数
    static QByteArray getSettingDispelTimeRequest(char minute);
    static QByteArray getSettingDispelTimeNormalResponse();

//    //    1	时间设置01	年	月	日	时	分	秒					1	时间设置01
//    static QByteArray getSettingTimeRequest(char year, char month, char day, char hour, char minute, char second);
//    static QByteArray getSettingTimeNormalResponse();
//    //    1	报警设置02	报警开关	报警上限	报警上限	报警上限	报警上限	报警下限	报警下限	报警下限	报警下限		1	报警设置02
//    static QByteArray getSettingAlarmRequest(char on, char up, char down);
//    static QByteArray getSettingAlarmNormalResponse();
//    //    1	预启设置03	预启时间										1	预启设置03
//    static QByteArray getSettingPreStartTimeRequest(char time);
//    static QByteArray getSettingPreStartTimeNormalResponse();
//    //    1	标1设置04	标1浓度	标1浓度	标1浓度	标1浓度							1	标1设置04
//    static QByteArray getSettingStdOneRequest(char std1);
//    static QByteArray getSettingStdOneNormalResponse();
//    //    1	标2设置05	标2浓度	标2浓度	标2浓度	标2浓度							1	标2设置05
//    static QByteArray getSettingStdTwoRequest(char std2);
//    static QByteArray getSettingStdTwoNormalResponse();
//    //    1	标3设置06	标3浓度	标3浓度	标3浓度	标3浓度							1	标3设置06
//    static QByteArray getSettingStdThreeRequest(char std3);
//    static QByteArray getSettingStdThreeNormalResponse();
//    //    1	量程温度时间设置07	量程	温度	消解时间								1	量程温度时间设置07
//    static QByteArray getSettingSpanTempTimeRequest(char span, char temp, char time);
//    static QByteArray getSettingSpanTempTimNormalResponse();
//    //    1	周期设置08	校准周期	校准时间	清洗周期	清洗时间							1	周期设置08
//    static QByteArray getSettingPeroidRequest(char calPeroid, char calTime, char washPeroid, char washTime);
//    static QByteArray getSettingPeroidNormalResponse();
//    //    1	自动间隔测量模式 09	自动测量间隔										1	自动间隔测量模式09
//    static QByteArray getSettingAutoIntervalMeansureModeRequest();
//    static QByteArray getSettingAutoIntervalMeansureModeNormalResponse();
//    //    1	整点测量间隔 10	0-7点（对应位置1）	8-15点（对应位置1）	16-23点（对应位置1）								1	整点测量间隔10
//    static QByteArray getSettingClockIntervalMeansureModeRequest();
//    static QByteArray getSettingClockIntervalMeansureModeNormalResponse();
//    //    1	手动测量模式 11											1	手动测量模式11
//    static QByteArray getSettingManualMeansureModeRequest();
//    static QByteArray getSettingManualMeansureModeNormalResponse();

    //    1	维护：测量22											1	维护：测量22
    static QByteArray getMeansureModeRequest();
    static QByteArray getMeansureModeNormalResponse();
    //    1	维护：校准23											1	维护：校准23
    static QByteArray getCalibrationRequest();
    static QByteArray getCalibrationNormalResponse();
    //    1	维护：初始化24											1	维护：初始化24
    static QByteArray getInitialRequest();
    static QByteArray getInitialNormalResponse();
    //    1	维护：除气泡25											1	维护：除气泡25
    static QByteArray getCleanBubbleRequest();
    static QByteArray getCleanBubbleNormalResponse();
    //    1	维护：清洗比色皿26											1	维护：清洗比色皿26
    static QByteArray getWashCuvetteRequest();
    static QByteArray getWashCuvetteNormalResponse();
    //    1	维护：试剂清洗比色皿27											1	维护：试剂清洗比色皿27
    static QByteArray getReagentWashCuvetteRequest();
    static QByteArray getReagentWashCuvetteNormalResponse();
    //    1	维护：结束处理28											1	维护：结束处理28
    static QByteArray getFinishDisposeRequest();
    static QByteArray getFinishDisposeNormalResponse();
    //    1	维护：零点检测29											1	维护：零点检测29
    static QByteArray getZeroMeansureRequest();
    static QByteArray getZeroMeansureNormalResponse();
    //    1	维护：紧急停止30											1	维护：紧急停止30
    static QByteArray getUrgencyStopRequest();
    static QByteArray getUrgencyStopNormalResponse();
    //        维护：查询状态31												维护：查询状态31	当前状态
    static QByteArray getSearchStatusRequest();
    static QByteArray getSearchStatusNormalResponse();
    //    1	维护：零点校准32											1	维护：零点校准32
    static QByteArray getZeroCalibrationRequest();
    static QByteArray getZeroCalibrationNormalResponse();
    //    1	维护：量程校准33											1	维护：量程校准33
    static QByteArray getSpanCalibrationRequest();
    static QByteArray getSpanCalibrationNormalResponse();
    //    1	测试：注射泵与十通阀测试36											1	测试：注射泵与十通阀测试36
    static QByteArray getInjectBumbValveRequest();
    static QByteArray getInjectBumbValveNormalResponse();
    //    1	测试：搅拌泵测试37											1	测试：搅拌泵测试37
    static QByteArray getMixingBumbRequest();
    static QByteArray getMixingBumbNormalResponse();
    //    1	测试：消解管风扇测试38											1	测试：消解管风扇测试38
    static QByteArray getDispelFanRequest();
    static QByteArray getDispelFanNormalResponse();
    //    1	测试：机柜风扇测试39											1	测试：机柜风扇测试39
    static QByteArray getBoxFanRequest();
    static QByteArray getBoxFanNormalResponse();
    //    1	测试：进水样40											1	测试：进水样40
    static QByteArray getInWaterRequest();
    static QByteArray getInWaterNormalResponse();
    //    1	测试：进零样41											1	测试：进零样41
    static QByteArray getInZeroRequest();
    static QByteArray getInZeroNormalResponse();
    //    1	测试：进标样42											1	测试：进标样42
    static QByteArray getInStdSampleRequest();
    static QByteArray getInStdSampleNormalResponse();
    //    1	测试：进试剂3 43											1	测试：进试剂3 43
    static QByteArray getInReagentThreeRequest();
    static QByteArray getInReagentThreeNormalResponse();
    //    1	测试：进试剂4 44											1	测试：进试剂4 44
    static QByteArray getInReagentFourRequest();
    static QByteArray getInReagentFourNormalResponse();
    //    1	测试：进试剂5 45											1	测试：进试剂5 45
    static QByteArray getInReagentFiveRequest();
    static QByteArray getInReagentFiveNormalResponse();
    //    1	系统信息46											1	系统信息46	电子签名共12字节	………
    static QByteArray getManufactureInfoRequest();
    static QByteArray getManufactureInfoNormalResponse();
    //    1	查询当前状态47 											1	查询当前状态47 	当前状态	当前动作	后续动作	当前消解池温度	当前环境温度	吸光度	吸光度	吸光度	吸光度	进度
    static QByteArray getRunningInfoRequest();
    static QByteArray getRunningInfoInfoNormalResponse();
    //    1	查询当前浓度48											1	查询当前浓度48	浓度值	浓度值（注：浓度值为整数，且为实际的100倍）
    static QByteArray getCurrentMeansureValueRequest();
    static QByteArray getCurrentMeansureValueNormalResponse();

    //    1	确认接收到的校正系数k，b49
    //    1	查询校准系数49 	校准曲线n
    static QByteArray getCalibrationCoefRequest(int n);
    static QByteArray getCalibrationCoefNormalResponse();

    //    动作代码	1 水样前预处理，2 蠕动泵采样，3 测量前管路清洗，4水样稀释，5 抽取试剂，6 消解管消解 ，7 比色测量 ，8测量后管路清洗
    //    状态代码	1在线测量，2离线测量，3零点校准 4 标准液校准
    //    错误代码	0x00状态正常，0x01帧错误  0x02 参数错误  0x03 光耦错误 0x04 电机忙 0xfe任务挂起 0xff 未知错误


    //校准曲线选择50
    //[2017:10:11:16:44:46][发送]01 50 03 5C 01
    //[2017:10:11:16:44:46][接收]01 50 03 5C 01
    //数据第3位03表示选择第三条校准曲线
    static QByteArray getSettingCalibrationCurveNumberRequest(int n);
    static QByteArray getSettingCalibrationCurveNumberNormalRespone();



    //    1	查询故障51 											0无故障，1比色皿温度异常，2冰箱温度异常，3注射泵异常，4切换阀异常
    static QByteArray getWarningInfoRequest();
    static QByteArray getWarningInfoInfoNormalResponse();

   //设置标样浓度
    static QByteArray getSettingSampleConsentrationRequest(int n);
    static QByteArray getSettingSampleConcentrationNormalResponse();


    //  报警上下限设置
    //    [2017:10:11:16:44:46][发送] 01 52 00 64 00 00 F9 D9
    //    [2017:10:11:16:44:46][接收] 01 52 00 64 00 00  F9 D9
    static QByteArray getAlertUpperLowZoneRequest(int upper,int low);
    static QByteArray getAlertUpperLowZoneNormalResponse();

    //    485使能设置
    //    [2017:10:11:16:44:46][发送] 01 53 00 1C F0
    //    [2017:10:11:16:44:46][接收] 01 53 00 1C F0
    //    数据第3位表示是否使能485通讯，0表示不使用，1表示使用
    static QByteArray getRS485AbleRequest(char isEnable);
    static QByteArray getRS485AbleNormalResponse();

    //    4~20mA使能设置
    //    [2017:10:11:16:44:46][发送] 01 54 00 1E C0
    //    [2017:10:11:16:44:46][接收] 01 54 00 1E C0
    //    数据第3位表示是否使能4~20mA通讯，0表示不使用，1表示使用
    static QByteArray get4to20mAAbleRequest(char isEnable);
    static QByteArray ge4to20mAAbleNormalResponse();

//    查询系统设置
//    [2017:10:11:16:44:46][发送] 01 55 C0 1F
//    [2017:10:11:16:44:46][接收] 01 55 00 00 00 00 0D C6
//    数据第3到第6位分别表示4~20mA状态，485状态，报警上限，报警下限，485通讯，0表示不使用，1表示使用，4~20mA通讯，0表示不使用，1表示使用，报警上限，报警下限都是8位无符号整数
    static QByteArray getSystemSettingDefaultInfoRequest();
    static QByteArray getSystemSettingDefaultInfoNormalResponse();

    //    查询参数设置
    //    [2017:10:11:16:44:46][发送] 01 56 80 1E
    //    [2017:10:11:16:44:46][接收] 01 56 01 01 21 98
    //    数据第3 ，第4位表示消解时间和采样泵启动时间，都是8位无符号整数
    static QByteArray getParameterSettingDefaultInfoRequest();
    static QByteArray getParameterSettingDefaultInfoNormalResponse();

//    查询周期设置
//    [2017:10:11:16:44:46][发送] 01 57 41 DE
//    [2017:10:11:16:44:46][接收] 01 57 00 01 01 C9 E4
//    数据第3 ，第4位，第5位表示测量模式，自动校准周期，自动测量间隔，都是8位无符号整数，其中测量模式 0表示自动，1表示手动
    static QByteArray getPeriodSettingDefaultInfoRequest();
    static QByteArray getPeriodSettingDefaultInfoNormalResponse();

//    查询标样浓度设置
//    [2017:10:11:16:44:46][发送] 01 58 01 DA
//    [2017:10:11:16:44:46][接收]  01 58 00 01 00 02 00 03 00 04 00 05 59 32
//    数据第3 到第12位表示曲线1到曲线5代表的浓度值，都是8位无符号整数，每两位代表一个浓度值，两个字节分别表示浓度值的高8位和低8位。
    static QByteArray getCalibrationSettingDefaultInfoRequest();
    static QByteArray getCalibrationSettingDefaultInfoNormalResponse();

//    测量模式设置
//    [2017:10:11:16:44:46][发送] 01 59 00 1A 50
//    [2017:10:11:16:44:46][接收]  01 59 00 1A 50
//    数据第3表示测量模式，0表示自动，1表示手动
    static QByteArray getSettingMeasureModeRequest(char mode);
    static QByteArray getSettingMeasureModeNomalRespsonse();

//    校准周期设置
//    [2017:10:11:16:44:46][发送] 01 60 00 08 00
//    [2017:10:11:16:44:46][接收] 01 60 00 08 00
//    数据第3表示校准周期时间，无符号整数
    static QByteArray getSettingCalibrationgPeriodRequest(char period);
    static QByteArray getSettingCalibrationgPeriodNomalRespsonse();

//    测量间隔设置
//    [2017:10:11:16:44:46][发送] 01 61 00 09 90
//    [2017:10:11:16:44:46][接收] 01 61 00 09 90
//    数据第3表示测量时间，无符号整数
    static QByteArray getSettingMeasureIntervalRequest(char interval);
    static QByteArray getSettingMeasureIntervalNomalRespsonse();

    static QByteArray getSelectedCurveRequest();
    static QByteArray getSelectedCurveNomalRespsonse();

    //   从站地址设置
    //   [2017:10:11:16:44:46][发送] 01 63 01 C9 30
    //   [2017:10:11:16:44:46][接收] 01 63 01 C9 30
    //   数据第3表示从站地址，无符号整数（1-31）
    static QByteArray getSettingSlaveAddressRequest(char slaveAddress);
    static QByteArray getSettingSlaveAddressNomalRespsonse();

};

#endif // STPROTOCOL2_H
