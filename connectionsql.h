#ifndef CONNECTIONSQL_H
#define CONNECTIONSQL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
class ConnectionSQL
{
private:
    static ConnectionSQL *connectionSQL;
    QSqlDatabase db;
    ConnectionSQL();
public:
    static ConnectionSQL *getConnection();

    QSqlDatabase &getDb();
};


#endif // CONNECTIONSQL_H
