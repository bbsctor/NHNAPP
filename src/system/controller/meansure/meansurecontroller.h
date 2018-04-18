#ifndef MEANSURECONTROLLER_H
#define MEANSURECONTROLLER_H
#include "../appcontroller.h"
#include "../../../framework/observe/qobservable.h"

class MeansureController : public AppController
{
    Q_OBJECT
public:
    MeansureController();
    enum Option{NO_OP, ONLINE_MEANSURE, OFFLINE_MEANSURE};
    void execute(Option option, QString paras);
    void execute(int action, QString paras);
    bool handleResponse(const QByteArray &resp);
    bool validate(const QByteArray &resp);
    void autoMeansureOn(int interval);
    void autoMeansureOff();
public slots:
    void meansureWrapper();
private:
    Option m_currentOption;
    QTimer* meansureTimer;
};

#endif // MEANSURECONTROLLER_H
