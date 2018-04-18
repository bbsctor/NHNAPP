#ifndef OPERATESERIALPORT_H
#define OPERATESERIALPORT_H
#include <QtSerialPort/QSerialPort>
#include <QMutex>
class Operateserialport
{
public:
    Operateserialport();
    int writeAndRead(QByteArray req,QByteArray & resp);
    void setPara(QString portName,qint32 baudRate,QSerialPort::DataBits dataBits,
                 QSerialPort::Parity parity,QSerialPort::StopBits stopBits);

    void openSerial();
    void closeSerial();
private:

    QSerialPort serial;
    QMutex mutex;

};

#endif // OPERATESERIALPORT_H
