#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    Login login;

    if(login.exec() == QDialog::Accepted){
       m.show();
       return a.exec();
    }
    return 0;
}
