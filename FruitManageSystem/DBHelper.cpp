#include "DBHelper.h"
#include <QDebug>
DBHelper *DBHelper::instance = NULL;

DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}
void DBHelper::connectDatabase()
{
    db.setDatabaseName("fruit.db");
    bool ret = db.open();
    if(ret){qDebug()<<"open db success";}
    else{qDebug()<<"open db failed";}
}

void DBHelper::disconnectDatabase()
{
    db.close();
    db.removeDatabase("fruit.db");
}


//开门
DBHelper *DBHelper::getInstance()
{
    if(instance == NULL)
    {
        instance = new DBHelper();
    }
    return instance;
}








