#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include "c_init_bd.h"
#include <QSqlQuery>
#include "connectionsql.h"
#include <map>

using namespace  std;



int main(int argc, char *argv[])
{

    // STL
    multimap<int, string> ml;
    ml.insert(make_pair(1,"titi"));
    ml.insert(make_pair(2,"toto"));
    ml.insert(make_pair(3,"tutu"));
    ml.insert(make_pair(4,"tata"));

    multimap<int, string>::iterator mit = ml.begin();

    mit = ml.find(3);
    ml.erase(mit);

    ml.insert(make_pair(0,"tete"));
    mit = ml.begin();
    for(mit;mit!=ml.end(); mit++){
        cout<<(*mit).second<<endl;
    }

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
    qDebug()<<
    connectionSQL->disconnect();
    return 0;
}
