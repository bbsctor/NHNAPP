#include "loginfodbhelper.h"

LogInfoDBHelper::LogInfoDBHelper()
{

}

bool LogInfoDBHelper::createTable()
{
    DBHelper::createConnection();
    QStringList tables = m_db.tables();
    if (tables.contains("logInfo", Qt::CaseInsensitive))
    {
        qWarning() << "logInfo table already existed!";
    }
    else {
        QSqlQuery query;
        query.exec("create table logInfo (datetime varchar(40), info varchar(20))");
        qWarning() << "logInfo table created successfully!";
    }
    return true;
}

bool LogInfoDBHelper::insert(QString datetime, QString info)
{
    QSqlQuery query;

    query.prepare("INSERT INTO logInfo (datetime, info) "
                   "VALUES (?, ?)");
    query.bindValue(0, QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss"));
    query.bindValue(1, info);

    if (query.exec() == true)
    {
         qWarning() << "logInfo table inserted successfully!";
    }
    else
    {
         qWarning() << "logInfo table inserted failed!";
    }
}

SqlQueryModel *LogInfoDBHelper::searchAll()
{
    qWarning() << "search logInfo table!";
    m_model->setQuery("SELECT * FROM logInfo  order by datetime desc");

    for (int i = 0; i < m_model->rowCount(); ++i) {
        QString datetime = m_model->record(i).value("datetime").toString();
        QString info = m_model->record(i).value("info").toString();
        qDebug() << datetime << info;
    }

    return m_model;
}

SqlQueryModel *LogInfoDBHelper::search(QString date)
{
    qWarning() << "search alertInfo table!";
//    QString now1=QDate::currentDate().toString("yyyy.MM.dd");
//    QString now2=QDate::currentDate().toString("yyyy.MM.dd");
    QString now1=date;
    QString now2=date;
    QString start=now1.append(" 00:00:00");
    QString stop=now2.append(" 23:59:59");

    QString sqlSelect="SELECT * FROM  logInfo where datetime between '"+start+"' and'"+stop+"' order by datetime desc";
//    QString sqlSelect="SELECT * FROM  alertInfo where datetime between '2017.11.14 00:00:00' and '2017.11.15 23:59:59' order by datetime desc";
    m_model->setQuery(sqlSelect);


//    m_model->setQuery("SELECT * FROM alertInfo order by datetime desc");

    for (int i = 0; i < m_model->rowCount(); ++i) {
        QString datetime = m_model->record(i).value("datetime").toString();
        QString info = m_model->record(i).value("info").toString();
        qDebug() << datetime << info;
    }

    return m_model;
}
