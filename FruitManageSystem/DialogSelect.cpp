#include "DialogSelect.h"
#include "ui_DialogSelect.h"
#include "FruitDaoImp.h"
#include "DBHelper.h"
#include <QDebug>
#include <QHeaderView>
DialogSelect::DialogSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelect)
{
    ui->setupUi(this);
    time = new QTimer(this);
    time->start(2000);
    model = new QSqlQueryModel(ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QObject::connect(time,SIGNAL(timeout()),this,SLOT(onTimeOut()));
}

DialogSelect::~DialogSelect()
{
    delete ui;
}

void DialogSelect::onTimeOut()
{
//    DBHelper *helper =  DBHelper::getInstance();
//    helper->connectDatabase();
//    QSqlQuery *query;
//    FruitDao *fd = new FruitDaoImp();
//    query = fd->selectFruitById(query,1);
//    model->setQuery(*query);
//    ui->tableView->setModel(model);
//    helper->disconnectDatabase();
    qDebug()<<"yes";

}

