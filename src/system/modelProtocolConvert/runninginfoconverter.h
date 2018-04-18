#ifndef RUNNINGINFOCONVERTER_H
#define RUNNINGINFOCONVERTER_H
#include "../dataModel/home/runninginfodatamodel.h"

class RunningInfoConverter
{
public:
    RunningInfoConverter();
    static void parseRunningInfo(QByteArray byteArray, RunningInfoDataModel* pModel);
    static ushort bytesToUint(QByteArray bytes);
};

#endif // RUNNINGINFOCONVERTER_H
