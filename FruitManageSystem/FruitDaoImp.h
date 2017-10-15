#ifndef FRUITDAOIMP_H
#define FRUITDAOIMP_H
#include "FruitDao.h"

class FruitDaoImp:public FruitDao
{
public:
    FruitDaoImp();
    QSqlQuery *selectFruitById(QSqlQuery *,int id);
    QSqlQuery *selectFruitByName(QSqlQuery *,QString name);
    QSqlQuery *selectFruitByPrice(QSqlQuery *,double price);
    QSqlQuery *selectFruitByNum(QSqlQuery *,double num);
    bool insertFruit(const Fruit &fruit);
    bool deleteFruit(const QString &name);
    bool updateFruit(const int &id,const Fruit &fruit);

};

#endif // FRUITDAOIMP_H
