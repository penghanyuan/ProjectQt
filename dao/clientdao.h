#ifndef CLIENTDAO_H
#define CLIENTDAO_H
#include "models/client.h"
#include "connectionsql.h"
#include <QSqlQuery>
#include <QSqlDatabase>

class ClientDAO
{
private:
    QSqlDatabase db;
public:
    ClientDAO();
    bool insertClient(Client &client);
    Client selectClientById(int id);
    Client selectClientListByLastname(QString lastname);
    Client selectClientListByFirstname(QString firstname);
    Client selectClientListByDate(QDate rdvDate);
};

#endif // CLIENTDAO_H
