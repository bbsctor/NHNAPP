#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>

class DataModel : public QObject
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = 0);

signals:

public slots:
};

#endif // DATAMODEL_H