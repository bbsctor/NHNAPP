#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>

class Operation : public QObject
{
    Q_OBJECT
public:
    explicit Operation(QObject *parent = 0);

signals:

public slots:
};

#endif // OPERATION_H