#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>

class DBManager : public QObject
{
    Q_OBJECT
public:
    explicit DBManager(QObject *parent = 0);

signals:

public slots:
};

#endif // DBMANAGER_H