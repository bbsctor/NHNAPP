# include "currentvalueconverter.h"

CurrentValueConverter::CurrentValueConverter()
{

}

uint CurrentValueConverter::bytesToUint(QByteArray bytes) {
    uint addr = bytes[3] & 0x000000FF;
    addr |= ((bytes[2] << 8) & 0x0000FF00);
    addr |= ((bytes[1] << 16) & 0x00FF0000);
    addr |= ((bytes[0] << 24) & 0xFF000000);
    return addr;
}


void CurrentValueConverter::parseCurrentValue(QByteArray byteArray, CurrentValueDataModel *pModel)
{
    QByteArray tempArray;
    tempArray.resize(4);
    if(byteArray.size() >=  5)
    {
        tempArray[0] = byteArray[2];
        tempArray[1] = byteArray[3];
        tempArray[2] = byteArray[4];
        tempArray[3] = byteArray[5];
    }
    uint tempValue = bytesToUint(tempArray);
    double realValue = (double)tempValue / 1000;
    if(realValue>0&&realValue<=10)
    {
        pModel->setCurrentValue(QString::number(realValue, 10 , 3));
    }
    else if(realValue>10&&realValue<=100)
    {
         pModel->setCurrentValue(QString::number(realValue, 10 , 2));
    }
    else if (realValue>100&&realValue<=300)
    {
         pModel->setCurrentValue(QString::number(realValue, 10 , 1));
    }
    else if(realValue>300)
    {
         pModel->setCurrentValue(QString::number(realValue, 10 , 1));
    }

}

int CurrentValueConverter::bytesToInt(QByteArray bytes) {
    int high = bytes[0];
    int low = bytes[1];
    return high * 256 + low;
}

