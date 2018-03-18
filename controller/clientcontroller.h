#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H
#include <QString>
#include <QDate>
#include "dao/clientdao.h"
class ClientController
{
private:
    ClientDAO clientDAO;
public:
    ClientController();
    bool addClient(QString lastname, QString firstname, QString address,QString city, QString postcode, QString tel, QString comment, QDate rdv_date, QString rdv_duration, QString res_string,int priority);

};

#endif // CLIENTCONTROLLER_H
