#ifndef STPROTOCOL1_H
#define STPROTOCOL1_H

#include "../../framework/protocoldef.h"
class STProtocol1 : public ProtocolDef
{
public:
    STProtocol1();

//    地址码	功能码	数据	数据	数据	数据	数据	数据	数据	数据	数据		地址码	功能码
//    1	时间设置01	年	月	日	时	分	秒					1	时间设置01
//    1	报警设置02	报警开关	报警上限	报警上限	报警上限	报警上限	报警下限	报警下限	报警下限	报警下限		1	报警设置02
//    1	预启设置03	预启时间										1	预启设置03
//    1	标1设置04	标1浓度	标1浓度	标1浓度	标1浓度							1	标1设置04
//    1	标2设置05	标2浓度	标2浓度	标2浓度	标2浓度							1	标2设置05
//    1	标3设置06	标3浓度	标3浓度	标3浓度	标3浓度							1	标3设置06
//    1	量程温度时间设置07	量程	温度	消解时间								1	量程温度时间设置07
//    1	周期设置08	校准周期	校准时间	清洗周期	清洗时间							1	周期设置08
//    1	自动间隔测量模式 09	自动测量间隔										1	自动间隔测量模式09
//    1	整点测量间隔 10	0-7点（对应位置1）	8-15点（对应位置1）	16-23点（对应位置1）								1	整点测量间隔10
//    1	手动测量模式 11											1	手动测量模式11
      static QByteArray getManualMeansureModeRequest();
      static QByteArray getManualMeansureModeNormalResponse();
//    1	维护：做样 12											1	维护：做样12
      static QByteArray getMakeSampleRequest();
      static QByteArray getMakeSampleNormalResponse();
//    1	维护：测零样13											1	维护：测零样13
      static QByteArray getZeroMeansureRequest();
      static QByteArray getZeroMeansureNormalResponse();
//    1	维护：测标1 14											1	维护：测标1 14
      static QByteArray getStdOneMeansureRequest();
      static QByteArray getgetStdOneMeansureNormalResponse();
//    1	维护：测标2 15											1	维护：测标2 15
      static QByteArray getStdTwoMeansureRequest();
      static QByteArray getgetStdTwoMeansureNormalResponse();
//    1	维护：调零  16
      static QByteArray getZeroSettingRequest();
      static QByteArray getZeroSettingNormalResponse();
//    1	维护：标1标 17											1	维护：标1标 17
      static QByteArray getStdOneDemarcateRequest();
      static QByteArray getStdOneDemarcateNormalResponse();
//    1	维护：标2标 18											1	维护：标2标 18
      static QByteArray getStdTwoDemarcateRequest();
      static QByteArray getStdTwoDemarcateNormalResponse();
//    1	维护：校准  19											1	维护：校准  19
      static QByteArray getCalibrationRequest();
      static QByteArray getCalibrationNormalResponse();
//    1	维护：清洗  20											1	维护：清洗  20
      static QByteArray getWashingRequest();
      static QByteArray getWashingNormalResponse();
//    1	维护：冲洗  21											1	维护：冲洗  21
      static QByteArray getFlushingRequest();
      static QByteArray getFlushingNormalResponse();
//    1	维护：初始装液 22											1	维护：初始装液 22
      static QByteArray getInitFillRequest();
      static QByteArray getInitFillNormalResponse();


//    1	测试：进水样 23											1	测试：进水样 23
      static QByteArray getInWaterRequest();
      static QByteArray getInWaterNormalResponse();
//    1	测试：进零样 24											1	测试：进零样 24
      static QByteArray getInZeroRequest();
      static QByteArray getInZeroNormalResponse();
//    1	测试：进标1  25											1	测试：进标1  25
      static QByteArray getInStdOneRequest();
      static QByteArray getInStdOneNormalResponse();
//    1	测试：进标2  26											1	测试：进标2  26
      static QByteArray getInStdTwoRequest();
      static QByteArray getInStdTwoNormalResponse();
//    1	测试：进试剂1 27											1	测试：进试剂1 27
      static QByteArray getInTestOneRequest();
      static QByteArray getInTestOneNormalResponse();
//    1	测试：进试剂2 28											1	测试：进试剂2 28
      static QByteArray getInTestTwoRequest();
      static QByteArray getInTestTwoNormalResponse();
//    1	测试：鼓泡 29											1	测试：鼓泡 29
      static QByteArray getBubbleRequest();
      static QByteArray getBubbleNormalResponse();
//    1	测试：加热 30											1	测试：加热 30
      static QByteArray getHeaterRequest();
      static QByteArray getHeaterNormalResponse();
//    1	测试：初始装液 31											1	测试：初始装液 31
      static QByteArray getTestInitFillRequest();
      static QByteArray getTestInitFillNormalResponse();
//    1	测试：清洗计量管 32											1	测试：清洗计量管 32
      static QByteArray getWashMeansureTubeRequest();
      static QByteArray getWashMeansureTubeNormalResponse();
//    1	测试：清洗消解瓶 33											1	测试：清洗消解瓶 33
      static QByteArray getWashDispelJarRequest();
      static QByteArray getWashDispelJarNormalResponse();


//    1	系统信息34											1	系统信息34	电子签名共12字节	………
      static QByteArray getManufactureInfoRequest();
      static QByteArray getManufactureInfoNormalResponse();
//    1	查询当前状态35 											1	查询当前状态35 	当前状态	当前动作	后续动作	当前消解池温度	当前环境温度	吸光度	吸光度	吸光度	吸光度	进度
      static QByteArray getRunningInfoRequest();
      static QByteArray getRunningInfoInfoNormalResponse();

//    动作代码	1 水样前预处理，2 蠕动泵采样，3 测量前管路清洗，4水样稀释，5 抽取试剂，6 消解管消解 ，7 比色测量 ，8测量后管路清洗
//    状态代码	1在线测量，2离线测量，3零点校准 4 标准液校准
//    错误代码	0x00状态正常，0x01帧错误  0x02 参数错误  0x03 光耦错误 0x04 电机忙 0xfe任务挂起 0xff 未知错误


};

#endif // STPROTOCOL1_H
