#ifndef ALERTINFODBHELPER_H
#define ALERTINFODBHELPER_H
#include "../../framework/database/dbhelper.h"

class AlertInfoDBHelper : public DBHelper
{
public:
    AlertInfoDBHelper();
    bool createTable();
    bool insert(QString datetime, QString info);
    SqlQueryModel* searchAll();
     SqlQueryModel* search(QString date);
};

#endif // ALERTINFODBHELPER_H
