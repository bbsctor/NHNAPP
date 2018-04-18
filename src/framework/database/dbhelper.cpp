#include "dbhelper.h"
#include <QDebug>

QSqlDatabase DBHelper::m_db;

DBHelper::DBHelper(QObject *parent) : QObject(parent)
{
    m_model = new SqlQueryModel();
}

bool DBHelper::createConnection()
{
    QDir dir;
    QString path;
    path=dir.currentPath();
    qWarning()<<path;
    DBHelper::m_db = QSqlDatabase::addDatabase("QSQLITE");
    DBHelper::m_db.setDatabaseName(path + "/NHNDB");
    if (!DBHelper::m_db.open()) {
        qWarning() << "connect failed!";
        return false;
    }
}

bool DBHelper::createTable()
{
    return true;
}
