#ifndef CALIBRATIONCOEFDATAMODEL_H
#define CALIBRATIONCOEFDATAMODEL_H
#include "../../../framework/datamodel.h"

class MaintainDataDataModel : public DataModel
{
public:
    MaintainDataDataModel();


    QString coefK1() const;
    void setCoefK1(const QString &coefK1);

    QString coefB1() const;
    void setCoefB1(const QString &coefB1);

    QString coefK2() const;
    void setCoefK2(const QString &coefK2);

    QString coefB2() const;
    void setCoefB2(const QString &coefB2);

    QString coefK3() const;
    void setCoefK3(const QString &coefK3);

    QString coefB3() const;
    void setCoefB3(const QString &coefB3);

    QString coefK4() const;
    void setCoefK4(const QString &coefK4);

    QString coefB4() const;
    void setCoefB4(const QString &coefB4);

    QString coefK5() const;
    void setCoefK5(const QString &coefK5);

    QString coefB5() const;
    void setCoefB5(const QString &coefB5);

private:
    QString m_coefK1;
    QString m_coefB1;
    QString m_coefK2;
    QString m_coefB2;
    QString m_coefK3;
    QString m_coefB3;
    QString m_coefK4;
    QString m_coefB4;
    QString m_coefK5;
    QString m_coefB5;
};

#endif // CALIBRATIONCOEFDATAMODEL_H
