#ifndef CLIENTDAO_H
#define CLIENTDAO_H
#include "models/client.h"
#include "connectionsql.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <vector>
using namespace std;


class ClientDAO
{
private:
    QSqlDatabase db;
public:
    ClientDAO();
    void insertClient(Client &client);
    Client selectClientById(int id);
    bool selectClientListByLastname(QString value, vector<Client> &clientList);
    Client selectClientListByFirstname(QString firstname);
    Client selectClientListByDate(QDate rdvDate);
};

#endif // CLIENTDAO_H
