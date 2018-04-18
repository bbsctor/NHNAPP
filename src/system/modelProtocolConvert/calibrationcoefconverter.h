#ifndef CALIBRATIONCOEFCONVERTER_H
#define CALIBRATIONCOEFCONVERTER_H
#include "../dataModel/maintain/calibrationcoefdatamodel.h"

class CalibrationCoefConverter
{
public:

    CalibrationCoefConverter();
    static void parseCalibrationCoef(QByteArray byteArray, MaintainDataDataModel* pModel);
private:
     static ushort bytesToUint(QByteArray bytes);
};

#endif // CALIBRATIONCOEFCONVERTER_H
