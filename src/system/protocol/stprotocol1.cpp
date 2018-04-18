#include "stprotocol1.h"
#include "../../framework/crc/JQChecksum.h"
using namespace JQChecksum;

STProtocol1::STProtocol1()
{

}
//[2017:04:26:10:25:04][发送]01 11 2C C0
//[2017:04:26:10:25:04][接收]01 11 2C C0


QByteArray STProtocol1::getManualMeansureModeRequest()
{   
    QByteArray ba;
     ba.resize(2);
     ba[0] = 0x01;
     ba[1] = 0x11;
//     ba[3] = 0x2C;
//     ba[2] = 0xC0;
     JQChecksum::appendCrc16ForModbus(ba);

     return ba;
}

QByteArray STProtocol1::getManualMeansureModeNormalResponse()
{
    QByteArray ba;
         ba.resize(4);
         ba[0] = 0x01;
         ba[1] = 0x11;
//         ba[3] = 0x2C;
//         ba[2] = 0xC0;
     JQChecksum::appendCrc16ForModbus(ba);

     return ba;
}

//[2017:04:26:10:25:19][发送]01 12 2D 80
//[2017:04:26:10:25:19][接收]01 12 2D 80
QByteArray STProtocol1::getMakeSampleRequest()
{
    QByteArray ba;
     ba.resize(2);
     ba[0] = 0x01;
     ba[1] = 0x12;
//     ba[3] = 0x2D;
//     ba[2] = 0x80;
     JQChecksum::appendCrc16ForModbus(ba);

     return ba;
}

QByteArray STProtocol1::getMakeSampleNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x12;
//    ba[3] = 0x2D;
//    ba[2] = 0x80;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

//[2017:04:26:10:35:17][发送]01 13 ED 41
//[2017:04:26:10:35:17][接收]01 13 ED 41

QByteArray STProtocol1::getZeroMeansureRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x13;
//    ba[3] = 0xED;
//    ba[2] = 0x41;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getZeroMeansureNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x13;
//    ba[3] = 0xED;
//    ba[2] = 0x41;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:26:27][发送]01 14 2F 00
//[2017:04:26:10:26:27][接收]01 14 2F 00

QByteArray STProtocol1::getStdOneMeansureRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x14;
//    ba[3] = 0x2F;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getgetStdOneMeansureNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x14;
//    ba[3] = 0x2F;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:26:49][发送]01 15 EF C1
//[2017:04:26:10:26:49][接收]01 15 EF C1

QByteArray STProtocol1::getStdTwoMeansureRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x15;
//    ba[3] = 0xEF;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getgetStdTwoMeansureNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x15;
//    ba[3] = 0xEF;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:27:05][发送]01 16 EE 81
//[2017:04:26:10:27:05][接收]01 16 EE 81

QByteArray STProtocol1::getZeroSettingRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x16;
//    ba[3] = 0xEE;
//    ba[2] = 0x81;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getZeroSettingNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x16;
//    ba[3] = 0xEE;
//    ba[2] = 0x81;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:27:25][发送]01 17 2E 40
//[2017:04:26:10:27:25][接收]01 17 2E 40

QByteArray STProtocol1::getStdOneDemarcateRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x17;
//    ba[3] = 0x2E;
//    ba[2] = 0x40;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getStdOneDemarcateNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x17;
//    ba[3] = 0x2E;
//    ba[2] = 0x40;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:28:15][发送]01 18 2A 00
//[2017:04:26:10:28:15][接收]01 18 2A 00

QByteArray STProtocol1::getStdTwoDemarcateRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x18;
//    ba[3] = 0x2A;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getStdTwoDemarcateNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x18;
//    ba[3] = 0x2A;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:28:36][发送]01 19 EA C1
//[2017:04:26:10:28:36][接收]01 19 EA C1

QByteArray STProtocol1::getCalibrationRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x19;
//    ba[3] = 0xEA;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getCalibrationNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x19;
//    ba[3] = 0xEA;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:28:54][发送]01 20 F8 01
//[2017:04:26:10:28:55][接收]01 20 F8 01


QByteArray STProtocol1::getWashingRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x20;
//    ba[3] = 0xF8;
//    ba[2] = 0x01;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getWashingNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x20;
//    ba[3] = 0xF8;
//    ba[2] = 0x01;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:29:13][发送]01 21 38 C0
//[2017:04:26:10:29:13][接收]01 21 38 C0

QByteArray STProtocol1::getFlushingRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x21;
//    ba[3] = 0x38;
//    ba[2] = 0xC0;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getFlushingNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x21;
//    ba[3] = 0x38;
//    ba[2] = 0xC0;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:29:32][发送]01 22 39 80
//[2017:04:26:10:29:32][接收]01 22 39 80

QByteArray STProtocol1::getInitFillRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x22;
//    ba[3] = 0x39;
//    ba[2] = 0x80;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getInitFillNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x22;
//    ba[3] = 0x39;
//    ba[2] = 0x80;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:29:56][发送]01 23 F9 41
//[2017:04:26:10:29:56][接收]01 23 F9 41
QByteArray STProtocol1::getInWaterRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x23;
//    ba[3] = 0xF9;
//    ba[2] = 0x41;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getInWaterNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x23;
//    ba[3] = 0xF9;
//    ba[2] = 0x41;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:30:09][发送]01 24 3B 00
//[2017:04:26:10:30:09][接收]01 24 3B 00
QByteArray STProtocol1::getInZeroRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x24;
//    ba[3] = 0x3B;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getInZeroNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x24;
//    ba[3] = 0x3B;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:30:31][发送]01 25 FB C1
//[2017:04:26:10:30:31][接收]01 25 FB C1
QByteArray STProtocol1::getInStdOneRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x25;
//    ba[3] = 0xFB;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getInStdOneNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x25;
//    ba[3] = 0xFB;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:31:14][发送]01 26 FA 81
//[2017:04:26:10:31:14][接收]01 26 FA 81
QByteArray STProtocol1::getInStdTwoRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x26;
//    ba[3] = 0xFA;
//    ba[2] = 0x81;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getInStdTwoNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x26;
//    ba[3] = 0xFA;
//    ba[2] = 0x81;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:31:31][发送]01 27 3A 40
//[2017:04:26:10:31:31][接收]01 27 3A 40
QByteArray STProtocol1::getInTestOneRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x27;
//    ba[3] = 0x3A;
//    ba[2] = 0x40;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getInTestOneNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x27;
//    ba[3] = 0x3A;
//    ba[2] = 0x40;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:31:43][发送]01 28 3E 00
//[2017:04:26:10:31:43][接收]01 28 3E 00
QByteArray STProtocol1::getInTestTwoRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x28;
//    ba[3] = 0x3E;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getInTestTwoNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x28;
//    ba[3] = 0x3E;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:33:02][发送]01 29 FE C1
//[2017:04:26:10:33:02][接收]01 29 FE C1
QByteArray STProtocol1::getBubbleRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x29;
//    ba[3] = 0xFE;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getBubbleNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x29;
//    ba[3] = 0xFE;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:33:21][发送]01 30 34 00
//[2017:04:26:10:33:22][接收]01 30 34 00
QByteArray STProtocol1::getHeaterRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x30;
//    ba[3] = 0x34;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getHeaterNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x30;
//    ba[3] = 0x34;
//    ba[2] = 0x00;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:33:40][发送]01 31 F4 C1
//[2017:04:26:10:33:40][接收]01 31 F4 C1
QByteArray STProtocol1::getTestInitFillRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x31;
//    ba[3] = 0xF4;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getTestInitFillNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x31;
//    ba[3] = 0xF4;
//    ba[2] = 0xC1;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:33:58][发送]01 32 F5 81
//[2017:04:26:10:33:58][接收]01 32 F5 81
QByteArray STProtocol1::getWashMeansureTubeRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x32;
//    ba[3] = 0xF5;
//    ba[2] = 0x81;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getWashMeansureTubeNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x32;
//    ba[3] = 0xF5;
//    ba[2] = 0x81;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:34:21][发送]01 33 35 40
//[2017:04:26:10:34:21][接收]01 33 35 40
QByteArray STProtocol1::getWashDispelJarRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x33;
//    ba[3] = 0x35;
//    ba[2] = 0x40;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getWashDispelJarNormalResponse()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x33;
//    ba[3] = 0x35;
//    ba[2] = 0x40;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}
//[2017:04:26:10:34:24][发送]01 34 F7 01
//[2017:04:26:10:34:24][接收]01 34 00 3D 00 27 34 35 51 17 32 38 38 35 2D DD
QByteArray STProtocol1::getManufactureInfoRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x34;
//    ba[3] = 0xF7;
//    ba[2] = 0x01;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getManufactureInfoNormalResponse()
{

}

//[2017:04:26:10:34:26][发送]01 35 37 C0
//[2017:04:26:10:34:27][接收]01 35 01 01 02 03 04 00 00 00 00 05 06 58

QByteArray STProtocol1::getRunningInfoRequest()
{
    QByteArray ba;
    ba.resize(4);
    ba[0] = 0x01;
    ba[1] = 0x35;
//    ba[2] = 0xC0;
//    ba[3] = 0x37;

    JQChecksum::appendCrc16ForModbus(ba);
    return ba;
}

QByteArray STProtocol1::getRunningInfoInfoNormalResponse()
{
    return NULL;
}
