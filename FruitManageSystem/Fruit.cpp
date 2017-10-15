#include "Fruit.h"

Fruit::Fruit(const QString &name, const double &price, const double &num)
    :name(name),price(price),num(num)
{

}

QString Fruit::getName() const
{
    return name;
}

double Fruit::getPrice() const
{
    return price;
}

double Fruit::getNum() const
{
    return num;
}
