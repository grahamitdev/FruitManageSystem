#include "MainWindow.h"
#include <QApplication>
#include "DBHelper.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();

    DBHelper *db = DBHelper::getInstance();
    if(db!=NULL)
    {
        delete(db);
        db = NULL;
    }

    return 0;
}
