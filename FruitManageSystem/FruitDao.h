#ifndef FRUITDAO_H
#define FRUITDAO_H
#include "Fruit.h"
#include <vector>
#include <QSqlQuery>
using namespace std;

class FruitDao
{
public:
    FruitDao();
    virtual QSqlQuery *selectFruitById(QSqlQuery *,int id) = 0;
    virtual QSqlQuery *selectFruitByName(QSqlQuery *,QString name) = 0;
    virtual QSqlQuery *selectFruitByPrice(QSqlQuery *,double price) = 0;
    virtual QSqlQuery *selectFruitByNum(QSqlQuery *,double num) = 0;

    virtual bool insertFruit(const Fruit &fruit) = 0;
    virtual bool deleteFruit(const QString &name) = 0;
    virtual bool updateFruit(const int &id,const Fruit &fruit) = 0;
    virtual ~FruitDao();
    //~FruitDao();
    //warning: deleting object of abstract class type 'FruitDao'
    //which has non-virtual destructor will cause undefined behaviour [-Wdelete-non-virtual-dtor] delete(fd);

};

#endif // FRUITDAO_H
