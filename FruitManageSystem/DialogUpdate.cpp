#include "DialogUpdate.h"
#include "ui_DialogUpdate.h"
#include <QMessageBox>
#include "FruitDaoImp.h"
DialogUpdate::DialogUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdate)
{
    ui->setupUi(this);
}

DialogUpdate::~DialogUpdate()
{
    delete ui;
}

void DialogUpdate::on_buttonBox_accepted()
{
    if(ui->le_id->text().isEmpty()||
            ui->le_name_new->text().isEmpty()||
            ui->le_price_new->text().isEmpty()||
            ui->le_num_new->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }
    int id = ui->le_id->text().toInt();
    QString name_new = ui->le_name_new->text();
    double price_new = ui->le_price_new->text().toDouble();
    double num_new = ui->le_num_new->text().toDouble();
    Fruit fruit(name_new,price_new,num_new);
    FruitDao *fd = new FruitDaoImp();
    int ret = fd->updateFruit(id,fruit);
    if(ret)
    {
        QMessageBox::information(this,"修改","修改成功");
    }
    else
    {
        QMessageBox::critical(this,"修改","修改失败");
    }
    delete(fd);
    fd=NULL;

}

void DialogUpdate::on_buttonBox_rejected()
{
    this->close();
}
