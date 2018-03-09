#include "connectionsql.h"

ConnectionSQL* ConnectionSQL::connectionSQL = NULL;
QSqlDatabase &ConnectionSQL::getDb()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");

    if(db.isValid())
    {
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");

        db.setDatabaseName("base_tmp.sqli");
        db.open();

        if(!db.isOpen())
        {
            qDebug() << db.lastError().text();
            qDebug() << "Erreur à louverture de la base !\n";
        }
    }
    return db;
}

ConnectionSQL::ConnectionSQL()
{

}

ConnectionSQL* ConnectionSQL::getConnection()
{
    if(connectionSQL==NULL)
    {
        connectionSQL = new ConnectionSQL();
    }
    return connectionSQL;
}

bool ConnectionSQL::disconnect()
{

}
