#ifndef CONNECTIONSQL_H
#define CONNECTIONSQL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
/**
 * @brief The ConnectionSQL class for getting a sql connection
 */
class ConnectionSQL
{
private:
    static ConnectionSQL *connectionSQL;
    QSqlDatabase db;
    ConnectionSQL();
public:
    static ConnectionSQL *getConnection();
    bool disconnect(){
        db.close();
        db.removeDatabase("QSQLITE");
        return true;
    };
    QSqlDatabase &getDb();
};


#endif // CONNECTIONSQL_H
