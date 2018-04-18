#ifndef LOGINFODBHELPER_H
#define LOGINFODBHELPER_H
#include "../../framework/database/dbhelper.h"

class LogInfoDBHelper : public DBHelper
{
public:
    LogInfoDBHelper();
    bool createTable();
    bool insert(QString datetime, QString info);
    SqlQueryModel* searchAll();
    SqlQueryModel* search(QString date);
};

#endif // LOGINFODBHELPER_H
