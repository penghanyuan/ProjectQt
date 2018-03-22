#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include "c_init_bd.h"
#include <QSqlQuery>
#include "connectionsql.h"

int main(int argc, char *argv[])
{
    // create database
    if(!QFile::exists("base_tmp.sqli"))
        C_INIT_BD::Creation_BD();
    QApplication a(argc, argv);
    MainWindow m;
    Login login;

    //set database connection
    ConnectionSQL *connectionSQL = ConnectionSQL::getConnection();

    if(login.exec() == QDialog::Accepted){
       m.show();
       return a.exec();
    }
    connectionSQL->disconnect();
    return 0;
}
