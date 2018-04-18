#ifndef HISTORYDATADBHELPER_H
#define HISTORYDATADBHELPER_H
#include "../../framework/database/dbhelper.h"

class HistoryDataDBHelper : public DBHelper
{
public:
    HistoryDataDBHelper();
    bool createTable();
    bool insert(QString datetime, QString value);
    SqlQueryModel* searchAll();
    SqlQueryModel* search(QString date);
};

#endif // HISTORYDATADBHELPER_H
