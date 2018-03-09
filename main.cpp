#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include "c_init_bd.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include "connectionsql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    Login login;
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    QSqlDatabase db = connection->getDb();

    QSqlQuery query;
    QString strSqlText("SELECT nom FROM TClient");//查询语法
    query.prepare(strSqlText);
    query.exec();
    while ( query.next() ) {
        QString name = query.value(0).toString();
        cout<< name.toStdString()<<endl ;
    }
    if(login.exec() == QDialog::Accepted){
       m.show();
       return a.exec();
    }
    db.close();
    db.removeDatabase("QSQLITE");
    return 0;
}
