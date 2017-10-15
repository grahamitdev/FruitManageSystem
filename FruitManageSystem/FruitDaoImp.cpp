#include "FruitDaoImp.h"
#include "DBHelper.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
FruitDaoImp::FruitDaoImp()
    :FruitDao()
{

}

QSqlQuery *FruitDaoImp::selectFruitById(QSqlQuery *query,int id)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    query->exec("create table if not exists tb_fruit("
                     "id integer primary key autoincrement,"
                     "name text not null,"
                     "price real not null,"
                     "num real not null"
                     ");");

    query->prepare("select id as '商品编号',"
                  "name as '名称',"
                  "price as '单价￥/0.5kg',"
                  "num as '数量'"
                  " from tb_fruit where id = :id;");
    query->bindValue(":id",id);
    query->exec();



    //helper->disconnectDatabase();
    return query;
}


QSqlQuery *FruitDaoImp::selectFruitByName(QSqlQuery * query,QString name)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    query->exec("create table if not exists tb_fruit("
                     "id integer primary key autoincrement,"
                     "name text not null,"
                     "price real not null,"
                     "num real not null"
                     ");");

    query->prepare("select id as '商品编号',"
                  "name as '名称',"
                  "price as '单价￥/0.5kg',"
                  "num as '数量'"
                  " from tb_fruit where name = :name;");
    query->bindValue(":name",name);
    query->exec();



    //helper->disconnectDatabase();
    return query;
}

QSqlQuery *FruitDaoImp::selectFruitByPrice(QSqlQuery * query,double price)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    query->exec("create table if not exists tb_fruit("
                     "id integer primary key autoincrement,"
                     "name text not null,"
                     "price real not null,"
                     "num real not null"
                     ");");

    query->prepare("select id as '商品编号',"
                  "name as '名称',"
                  "price as '单价￥/0.5kg',"
                  "num as '数量'"
                  " from tb_fruit where price = :price;");
    query->bindValue(":price",price);
    query->exec();



    //helper->disconnectDatabase();
    return query;
}

QSqlQuery *FruitDaoImp::selectFruitByNum(QSqlQuery * query,double num)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    query->exec("create table if not exists tb_fruit("
                     "id integer primary key autoincrement,"
                     "name text not null,"
                     "price real not null,"
                     "num real not null"
                     ");");

    query->prepare("select id as '商品编号',"
                  "name as '名称',"
                  "price as '单价￥/0.5kg',"
                  "num as '数量'"
                  " from tb_fruit where num = :num;");
    query->bindValue(":num",num);
    query->exec();



    //helper->disconnectDatabase();
    return query;
}

bool FruitDaoImp::insertFruit(const Fruit &fruit)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec("create table if not exists tb_fruit("
                     "id integer primary key autoincrement,"
                     "name text not null,"
                     "price real not null,"
                     "num real not null"
                     ");");
    if(ret){qDebug()<<"create tb_fruit success";}
    else{qDebug()<<query.lastError().text();}

    query.prepare("insert into tb_fruit(name,price,num)"
                  "values(:name,:price,:num);");
    query.bindValue(":name",fruit.getName());
    query.bindValue(":price",fruit.getPrice());
    query.bindValue(":num",fruit.getNum());
    ret = query.exec();
    if(ret){qDebug()<<"DaoImp insert success";}
    else{qDebug()<<query.lastError().text();}

    helper->disconnectDatabase();
    return ret;
}









bool FruitDaoImp::deleteFruit(const QString &name)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec("create table if not exists tb_fruit("
                     "id integer primary key autoincrement,"
                     "name text not null,"
                     "price real not null,"
                     "num real not null"
                     ");");
    if(ret){qDebug()<<"create tb_fruit success";}
    else{qDebug()<<query.lastError().text();}

    query.prepare("delete from tb_fruit where name = :name;");
    query.bindValue(":name",name);

    ret = query.exec();
    if(ret){qDebug()<<"DaoImp delete success";}
    else{qDebug()<<query.lastError().text();}

    helper->disconnectDatabase();
    return ret;
}

bool FruitDaoImp::updateFruit(const int &id, const Fruit &fruit)
{
    qDebug()<<"yes1";
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec("create table if not exists tb_fruit("
                     "id integer primary key autoincrement,"
                     "name text not null,"
                     "price real not null,"
                     "num real not null"
                     ");");
    if(ret){qDebug()<<"create tb_fruit success";}
    else{qDebug()<<query.lastError().text();}
qDebug()<<"yes2";
    query.prepare("select * from tb_fruit where name = :id;");
    query.bindValue(":id",id);
qDebug()<<"yes3";
    ret = query.exec();
    if(!ret)
    {
        qDebug()<<query.lastError().text()<<" not find";
        return ret;
    }
    else
    {
        qDebug()<<"find";
        QString name_new = fruit.getName();
        double price_new = fruit.getPrice();
        double num_new = fruit.getNum();
        query.prepare("update tb_fruit "
                      "set name = :name_new,"
                      "price = :price_new,"
                      "num = :num_new"
                      "where id = :id;");

        query.bindValue(":id",id);
        query.bindValue(":name_new",name_new);
        query.bindValue(":price_new",price_new);
        query.bindValue(":num_new",num_new);
        ret = query.exec();
        if(ret){qDebug()<<"修改成功";}
        else{qDebug()<<query.lastError().text()<<"修改失败";}
    }


    helper->disconnectDatabase();
    return ret;
}






























