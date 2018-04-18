#include "historydatadbhelper.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

HistoryDataDBHelper::HistoryDataDBHelper()
{

}

bool HistoryDataDBHelper::createTable()
{
    DBHelper::createConnection();
    QStringList tables = m_db.tables();
    if (tables.contains("meansure", Qt::CaseInsensitive))
    {
        qWarning() << "meansure table already existed!";
    }
    else {
        QSqlQuery query;
        query.exec("create table meansure (datetime varchar(40), value varchar(20))");
        qWarning() << "meansure table created successfully!";
    }

    return true;
}

bool HistoryDataDBHelper::insert(QString datetime, QString value)
{
    QSqlQuery query;

         query.prepare("INSERT INTO meansure (datetime, value) "
                       "VALUES (?, ?)");
         query.bindValue(0, QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss"));
         query.bindValue(1, value);

         if (query.exec() == true)
         {
             qWarning() << "meansure table inserted successfully!";
         }
         else
         {
             qWarning() << "meansure table inserted failed!";
         }

}

SqlQueryModel* HistoryDataDBHelper::searchAll()
{
    qWarning() << "search meansure table!";
    m_model->setQuery("SELECT * FROM meansure order by datetime desc");

    for (int i = 0; i < m_model->rowCount(); ++i) {
        QString datetime = m_model->record(i).value("datetime").toString();
        QString value = m_model->record(i).value("value").toString();
        qDebug() << datetime << value;
    }

    return m_model;
}

SqlQueryModel *HistoryDataDBHelper::search(QString date)
{
    qWarning() << "search alertInfo table!";
//    QString now1=QDate::currentDate().toString("yyyy.MM.dd");
//    QString now2=QDate::currentDate().toString("yyyy.MM.dd");
    QString now1=date;
    QString now2=date;
    QString start=now1.append(" 00:00:00");
    QString stop=now2.append(" 23:59:59");

    QString sqlSelect="SELECT * FROM  meansure where datetime between '"+start+"' and'"+stop+"' order by datetime desc";
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
