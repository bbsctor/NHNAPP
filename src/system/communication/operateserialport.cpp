#include "operateserialport.h"
#include <QDebug>

Operateserialport::Operateserialport()
{

}
void Operateserialport::openSerial()
{
    serial.open(QIODevice::ReadWrite);
    qWarning()<<"serial.open!";

}
void Operateserialport::closeSerial()
{
    serial.close();
}

int Operateserialport::writeAndRead(QByteArray req, QByteArray &resp)
{
    int currentWaitTimeout = 1500;
    int reCount=0;

    int ret=0;

    while (true) {

        // write request
        QByteArray requestData = req;
        serial.write(requestData);
        if (serial.waitForBytesWritten(currentWaitTimeout)) {

            // read response
            if (serial.waitForReadyRead(currentWaitTimeout)) {
                resp = serial.readAll();
                while (serial.waitForReadyRead(50))
                    resp += serial.readAll();

                break;

            } else {
                //emit timeout(tr("Wait read response timeout %1")
                 //            .arg(QTime::currentTime().toString()));
                if(reCount < 3)
                {
                    reCount++;
                }
                else
                {
                    reCount = 0;
                    ret=-1;
                    break;
                }
            }

        } else {
           // emit timeout(tr("Wait write request timeout %1")
            //             .arg(QTime::currentTime().toString()));
            if(reCount < 3)
            {
                reCount++;
            }
            else
            {
                reCount = 0;
                ret = -1;
                break;
            }

        }
        mutex.lock();
        serial.clear();
        mutex.unlock();
    }
    return ret;
}



void Operateserialport::setPara(QString portName,qint32 baudRate,QSerialPort::DataBits dataBits,
                           QSerialPort::Parity parity,QSerialPort::StopBits stopBits)
{
        serial.setPortName(portName);
        serial.setBaudRate(baudRate);
        serial.setDataBits(dataBits);
        serial.setParity(parity);
        serial.setStopBits(stopBits);
}
