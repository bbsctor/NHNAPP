#ifndef WARNINGCONVERTER_H
#define WARNINGCONVERTER_H
#include "../dataModel/warning/warningdatamodel.h"

class WarningConverter
{
public:
    WarningConverter();
    static void parseWarningInfo(QByteArray byteArray, WarningDataModel* pModel);
};

#endif // WARNINGCONVERTER_H
