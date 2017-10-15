#include "DialogInsert.h"
#include "ui_DialogInsert.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
DialogInsert::DialogInsert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInsert)
{
    ui->setupUi(this);    
}

DialogInsert::~DialogInsert()
{
    delete ui;
}

void DialogInsert::on_buttonBox_accepted()
{
    if(ui->le_name->text().isEmpty()||
            ui->le_price->text().isEmpty()||
            ui->le_num->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    QString name = ui->le_name->text();
    double price = ui->le_price->text().toDouble();
    double num = ui->le_num->text().toDouble();
    Fruit fruit(name,price,num);

    emit sigInsert(fruit);
}

void DialogInsert::on_buttonBox_rejected()
{
    this->close();
}
