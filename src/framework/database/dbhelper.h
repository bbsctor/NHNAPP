#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "../../framework/database/sqlquerymodel.h"

class DBHelper : public QObject
{
    Q_OBJECT
public:
    explicit DBHelper(QObject *parent = 0);
    static bool createConnection();
    virtual bool createTable();
//    SqlQueryModel *model() const;
//    void setModel(SqlQueryModel *model);

//    QSqlDatabase db() const;
//    void setDb(const QSqlDatabase &db);

signals:

public slots:
protected:
    SqlQueryModel* m_model;
    static QSqlDatabase m_db;
};

#endif // DBHELPER_H
