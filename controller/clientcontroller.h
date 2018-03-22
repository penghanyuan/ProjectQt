#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H
#include <QString>
#include <QDate>
#include "dao/clientdao.h"
#include "controller/appointmentcontroller.h"
class ClientController
{
private:
    ClientDAO clientDAO;
    AppointmentController appointmentController;
public:
    ClientController();
    bool addClient(QString lastname, QString firstname, QString address,QString city, QString postcode, QString tel, QString comment, QDate rdv_date, QString rdv_duration, QString res_string,int priority);
    void getAllClient(vector<Client>&clients);
    void getClientByFirstName(vector<Client>&clients,QString firstname);
    void getClientByLastName(vector<Client>&clients,QString firstname);
    void getClientByDate(vector<Client>&clients, QString date);

};

#endif // CLIENTCONTROLLER_H
