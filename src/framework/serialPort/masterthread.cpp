/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "masterthread.h"
#include <QDebug>
#include <QTime>
#include <QDebug>
#include <atomic>

#include "../../system/communication/serveritem.h"
#include "../../system/communication/communicationserver.h"

QT_USE_NAMESPACE

MasterThread::MasterThread(QObject *parent)
    : QThread(parent), waitTimeout(0), quit(false)
{
    setPara("COM3",QSerialPort::Baud9600,QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop);
    serial.open(QIODevice::ReadWrite);
}

//! [0]
MasterThread::~MasterThread()
{
    mutex.lock();
    quit = true;
    cond.wakeOne();
    mutex.unlock();
    wait();
}
//! [0]

//! [1] //! [2]
void MasterThread::transaction(const QString &portName, int waitTimeout, const QByteArray &request)
{
    //! [1]
    qWarning()<<"portName: " << portName;
    QMutexLocker locker(&mutex);
    this->portName = portName;
    this->waitTimeout = waitTimeout;
    this->request = request;
    //! [3]
    if (!isRunning())
        start();
    else
        cond.wakeOne();
}
//! [2] //! [3]

//! [4]

void MasterThread::run()
{

    int currentWaitTimeout = 2000;

    //QList<ServerItem>  * itemlistPtr;

    ServerItem itemNow;
    //QByteArray currentRequest;
    bool timeoutflag=false;
    int reCount=0;
    while (!quit) {

        if (!timeoutflag) {
            //判断是否处于timeout状态，不是则 取list中的数据
           itemNow =  CommunicationServer::getInstance()->getone();
           if( itemNow.controllerPtr == NULL )
           {
                 continue;
           }
        }

        // write request
        //QByteArray requestData = currentRequest;
        QByteArray requestData= itemNow.req;
        serial.write(requestData);
        qWarning()<<" serial.write(requestData)";
        if (serial.waitForBytesWritten(currentWaitTimeout)) {

            // read response
             qWarning()<<"  read response";
            if (serial.waitForReadyRead(currentWaitTimeout)) {
                //std::atomic< QByteArray>  responseData;
                mutex.lock();
                //QByteArray  responseData = serial.readAll();
                QByteArray  responseData = serial.readAll();
                while (serial.waitForReadyRead(20))
                    responseData += serial.readAll();

               // emit this->response(responseData);

                itemNow.resp=responseData;
                itemNow.controllerPtr->handleResponse( itemNow.resp);
                mutex.unlock();
                timeoutflag=false;
                 qWarning()<<" handleResponse handleResponse handleResponse over over over";

            } else {
                //emit timeout(tr("Wait read response timeout %1")
                 //            .arg(QTime::currentTime().toString()));
                timeoutflag = true;
                qWarning()<<"read failed!";
                if(reCount < 3)
                {
                    reCount++;
                }
                else
                {
                    reCount = 0;
                    timeoutflag=false;
                }

               // continue;
            }

        } else {
           // emit timeout(tr("Wait write request timeout %1")
            //             .arg(QTime::currentTime().toString()));

             timeoutflag = true;
             qWarning()<<"read failed!";
            if(reCount < 3)
            {
                reCount++;
            }
            else
            {
                reCount = 0;
                timeoutflag=false;
            }
        }

        mutex.lock();
        serial.clear();
        mutex.unlock();
    }
    //! [13]
}


bool MasterThread::sendAndRecv(QByteArray& req, QByteArray& resp)
{
    int currentWaitTimeout = 3000;
    mutex.lock();
    bool success = true;
    serial.write(req);
    if (serial.waitForBytesWritten(currentWaitTimeout)) {
        if (serial.waitForReadyRead(currentWaitTimeout)) {
            resp = serial.readAll();
            while (serial.waitForReadyRead(100))
                resp += serial.readAll();
        } else {
                success = false;
        }
    } else {
        success = false;
    }
    mutex.unlock();
    return success;
}

//void MasterThread::run()
//{
//    ServerItem itemNow;

//    while (!quit) {
//           itemNow =  CommunicationServer::getInstance()->getone();
//           if( itemNow.controllerPtr == NULL )
//           {
//                 continue;
//           }
//           bool success = sendAndRecv(itemNow.req, itemNow.resp);
//           if(success == true)
//           {
//                itemNow.controllerPtr->handleResponse( itemNow.resp);
//           }
//           else
//           {
//                qWarning()<<"read failed!";
//           }
//        }

//}

void MasterThread::setPara(QString portName,qint32 baudRate,QSerialPort::DataBits dataBits,
                           QSerialPort::Parity parity,QSerialPort::StopBits stopBits)
{
        serial.setPortName(portName);
        serial.setBaudRate(baudRate);
        serial.setDataBits(dataBits);
        serial.setParity(parity);
        serial.setStopBits(stopBits);
}
