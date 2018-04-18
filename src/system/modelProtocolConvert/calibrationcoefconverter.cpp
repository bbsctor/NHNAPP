#include "calibrationcoefconverter.h"

CalibrationCoefConverter::CalibrationCoefConverter()
{

}
ushort CalibrationCoefConverter::bytesToUint(QByteArray bytes) {
    ushort addr = bytes[1] & 0x000000FF;
    addr |= ((bytes[0] << 8) & 0x0000FF00);
   //uint addr |= ((bytes[1] << 16) & 0x00FF0000);
   // addr |= ((bytes[0] << 24) & 0xFF000000);
    return addr;
}
void CalibrationCoefConverter::parseCalibrationCoef(QByteArray byteArray, MaintainDataDataModel *pModel)
{
    bool ok;
    int n;
    n = byteArray[2];
    QByteArray temp;

    temp.resize(2);
    if(byteArray.size() >=  5)
    {
         temp[0] = byteArray[3];
         temp[1] = byteArray[4];
    }


   // double tempValue = temp.toShort(&ok, 10);
    ushort tempValue=bytesToUint(temp);
//    ushort tempValue = temp[0] * 256 + temp[1];
    short tempValue2 = (short)tempValue;
    double realValue = (double)tempValue2 / 10000;

    switch(n)
    {
        case 1:
            pModel->setCoefK1(QString::number(realValue, 10 , 3));
            break;
        case 2:
            pModel->setCoefK2(QString::number(realValue, 10 , 3));
            break;
        case 3:
            pModel->setCoefK3(QString::number(realValue, 10 , 3));
            break;
        case 4:
            pModel->setCoefK4(QString::number(realValue, 10 , 3));
            break;
        case 5:
            pModel->setCoefK5(QString::number(realValue, 10 ,3));
            break;
    }

    temp[0] = byteArray[5];
    temp[1] = byteArray[6];

  //  tempValue = temp.toShort(&ok, 10);
    //tempValue =  (uchar)byteArray[4] * 256 + (uchar)byteArray[5];
  //  realValue = (double)tempValue / 10000;
    tempValue=bytesToUint(temp);
//    ushort tempValue = temp[0] * 256 + temp[1];
     tempValue2 = (short)tempValue;
     realValue = (double)tempValue2 / 10000;

    switch(n)
    {
        case 1:
            pModel->setCoefB1(QString::number(realValue, 10 , 3));
            break;
        case 2:
            pModel->setCoefB2(QString::number(realValue, 10 , 3));
            break;
        case 3:
            pModel->setCoefB3(QString::number(realValue, 10 , 3));
            break;
        case 4:
            pModel->setCoefB4(QString::number(realValue, 10 , 3));
            break;
        case 5:
            pModel->setCoefB5(QString::number(realValue, 10 , 3));
            break;
    }
}
