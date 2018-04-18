#ifndef SYSTEMMAINTAINCONTROLLER_H
#define SYSTEMMAINTAINCONTROLLER_H
#include "../appcontroller.h"

class SystemMaintainController : public AppController
{
    Q_OBJECT
public:
    SystemMaintainController();
    enum Option{NO_OP, MEANSURE, CALIBRATION, INIT, CLEANBUBBLE, WASHCUVETTE, REVGENTWASHCUVETTE, FINISHDISPOSE, ZEROMEANSURE, URGENCYSTOP, SEARCHSTATUS,
               ZEROCALIBRATION, SPANCALIBRATION};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
    bool validate(const QByteArray &resp);
    void periodCalibrationOff();
    void periodCalibrationOn(int interval);
public slots:
    void updateCalibrationCoef();
    void calibrationWrapper();
private:
    Option m_currentOption;
    QTimer* calibrationTimer;
};

#endif // SYSTEMMAINTAINCONTROLLER_H
