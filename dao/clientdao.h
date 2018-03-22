#ifndef CLIENTDAO_H
#define CLIENTDAO_H
#include "models/client.h"
#include "connectionsql.h"
#include "dao/appointmentdao.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <vector>
using namespace std;


class ClientDAO
{
private:
    QSqlDatabase db;
    AppointmentDAO appointmentDAO;
public:
    ClientDAO();
    bool insertClient(Client &client);
    Client getClientInfo(QSqlQuery query);
    Client selectClientById(int id);
    bool selectClientListByLastname(QString value, vector<Client> &clientList);
    bool selectClientListByFirstname(QString value, vector<Client> &clientList);
    bool selectClientListByDate(vector<Client> &clientList, QString rdvBeginDate, QString rdvEndDate);
    bool selectAllClients(vector<Client> &clientList);
    bool modifyClient(Client &client, int id);
    bool deleteClient(int id);
    int selectMaxId();
};

#endif // CLIENTDAO_H
