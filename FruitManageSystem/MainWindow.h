#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DialogInsert.h"
#include "Fruit.h"
#include "DialogDelete.h"
#include "DialogUpdate.h"
#include "DialogSelect.h"
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void selectMethod();

private slots:    

    void on_btn_insert_clicked();

    void on_btn_delete_clicked();

    void on_btn_alter_clicked();

    void on_btn_query_clicked();

    void on_btn_out_clicked();

    void onSigInsert(const Fruit &fruit);    

    void onTimeout();

    void onTimeoutCurrentTime();



private:
    Ui::MainWindow *ui;
    DialogInsert *dialogInsert;    
    DialogDelete *dialogDelete;
    DialogUpdate *dialogUpdate;
    DialogSelect *dialogSelect;
    QTimer *timer;
    QTimer *timerCurrentTime;    
    QSqlQueryModel *model;
    //QStandardItemModel *model;

};

#endif // MAINWINDOW_H
