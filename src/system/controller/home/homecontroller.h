#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H
#include "../appcontroller.h"
#include <QTime>

class HomeController : public AppController
{
    Q_OBJECT
public:
    HomeController();
    enum Option{NO_OP, URGENCYSTOP, INIT};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
    bool validate(const QByteArray &resp);
    void updateRunningInfo();
    void updateWarningInfo();
    void updateLoop();
public slots:
    void autoMeansureAndCalibrationStart();
private:
    Option m_currentOption;
    QTimer* timer;
};

#endif // HOMECONTROLLER_H
