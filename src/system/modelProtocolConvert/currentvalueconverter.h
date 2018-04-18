#ifndef CURRENTVALUECONVERTER_H
#define CURRENTVALUECONVERTER_H
#include "../dataModel/home/currentvaluedatamodel.h"

class CurrentValueConverter
{
public:
    CurrentValueConverter();
    static void parseCurrentValue(QByteArray byteArray, CurrentValueDataModel* pModel);
private:
    int bytesToInt(QByteArray bytes);
    static uint bytesToUint(QByteArray bytes);
};

#endif // CURRENTVALUECONVERTER_H
