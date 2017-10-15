#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "FruitDaoImp.h"
#include <QDebug>
#include "DBHelper.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>
#include <QThread>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->hide();
    /**二级界面**/
    dialogInsert = new DialogInsert(this);
    dialogDelete = new DialogDelete(this);
    dialogUpdate = new DialogUpdate(this);
    dialogSelect = new DialogSelect(this);
    /**设置二级界面为模态**/
    dialogInsert->setWindowModality(Qt::ApplicationModal);
    dialogDelete->setWindowModality(Qt::ApplicationModal);
    dialogUpdate->setWindowModality(Qt::ApplicationModal);
    dialogSelect->setWindowModality(Qt::ApplicationModal);

    /**定时2秒产生一个超时信号，当超时信号产生时触发槽函数**/
    timer = new QTimer(this);
    timer->start(2000);
    timerCurrentTime = new QTimer(this);
    timerCurrentTime->start(1000);

    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    /**连接主界面二级界面信号--槽**/
    QObject::connect(dialogInsert,SIGNAL(sigInsert(const Fruit &)),this,SLOT(onSigInsert(const Fruit &)));
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    QObject::connect(timerCurrentTime,SIGNAL(timeout()),this,SLOT(onTimeoutCurrentTime()));
    /* 曾一度认为信号--槽参数如果使用指针/引用，
     * 则当信号传输到槽的时候，所传输的指针/引用指向内存已经释放，
     * 因此槽接收到的是野指针/无效引用。因此，信号/槽的参数只能使用值传递。
     * 现在才发现上面的认识是错误的！！！
     * 在单线程的情况之下，就算信号--槽使用了引用类型的参数也是允许的。
     * 由于是单线程，槽接收到引用时发送信号的函数其实还没结束，
     * 因此就算传递过来的是一个局部变量的引用，也是有效的。
     * 当槽返回的时候，发送信号的函数再继续往下执行，这其实就相当于单片机中断处理。
     * 当信号--槽的参数是引用类型时，在连接时无需指明，connect()会忽略const和&
     **
     * 如果信号和槽函数的参数类型都是Fruit类型，emit 信号之后，会发生两次拷贝的过程。
     * 如果信号和槽函数的类型一个是引用，一个是非引用时，connect 的时候会发生类型不匹配的错误：
     * 信号和槽函数的类型可以同时为引用类型，此时可以减少传递过程中拷贝的开销。
     * 对于跨线程的信号槽链接，信号和槽函数的类型必须为元类型，对于自定义的类型，需要注册为元类型：
     * qRegisterMetaType<Fruit>("Fruit");*/






    /**废弃**/
    //    model = new QStandardItemModel();
    //    model->setColumnCount(3);
    //    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("名称")));
    //    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("价格￥/0.5kg")));
    //    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("数量/kg")));
    //    ui->tableView->setModel(model);


    //    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Fixed);
    //    ui->tableView->setColumnWidth(0,150);
    //    ui->tableView->setColumnWidth(1,150);
    //    ui->tableView->setColumnWidth(2,150);
    //    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectMethod()
{
    DBHelper *helper =  DBHelper::getInstance();
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
    model->setQuery("select id as '商品编号',"
                    "name as '名称',"
                    "price as '单价￥/0.5kg',"
                    "num as '数量/kg' from tb_fruit;");



    /**将数据库的信息显示到tabaleView**/
    ui->tableView->setModel(model);

    helper->disconnectDatabase();
}
void MainWindow::onTimeout()
{
    selectMethod();
}
void MainWindow::onTimeoutCurrentTime()
{
    ui->lb_time->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
}

void MainWindow::on_btn_insert_clicked()
{
    dialogInsert->show();
}

void MainWindow::on_btn_delete_clicked()
{
    dialogDelete->show();
}

void MainWindow::on_btn_alter_clicked()
{
    dialogUpdate->show();
}

void MainWindow::on_btn_query_clicked()
{
    dialogSelect->show();
}

void MainWindow::onSigInsert(const Fruit &fruit)
{
    FruitDao *fd = new FruitDaoImp();
    if(fd->insertFruit(fruit))
    {
        qDebug()<<"insert success";
        QMessageBox::information(this,"插入","插入成功");
    }
    else
    {
        qDebug()<<"insert failed";
        QMessageBox::critical(this,"插入","插入失败，请重新插入");
    }
}





void MainWindow::on_btn_out_clicked()
{
    ui->progressBar->show();
    int num = 10;
    int i = 0;
    ui->progressBar->setRange(0,num);
    for(i = 0;i<=num;++i)
    {
        ui->progressBar->setValue(i);
        QThread::msleep(100);
    }
    ui->progressBar->hide();
}
