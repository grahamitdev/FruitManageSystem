#ifndef FRUIT_H
#define FRUIT_H

#include <QString>
class Fruit
{
public:
    Fruit(const QString &name,const double &price,const double &num);
    QString getName()const;
    double getPrice()const;
    double getNum()const;
private:    
    QString name;
    double price;
    double num;
};

#endif // FRUIT_H
