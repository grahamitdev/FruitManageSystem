#ifndef DIALOGINSERT_H
#define DIALOGINSERT_H

#include <QDialog>
#include "Fruit.h"
namespace Ui {
class DialogInsert;
}

class DialogInsert : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInsert(QWidget *parent = 0);
    ~DialogInsert();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
signals:
    void sigInsert(const Fruit &fruit);

private:
    Ui::DialogInsert *ui;    
};

#endif // DIALOGINSERT_H
