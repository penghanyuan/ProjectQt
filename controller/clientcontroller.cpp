#include "clientcontroller.h"
#include <QDebug>
ClientController::ClientController()
{

}

bool ClientController::addClient(QString lastname, QString firstname, QString address, QString city, QString postcode, QString tel, QString comment, QDate rdv_date, QString rdv_duration, QString res_string, int priority)
{
    Client client;
    client.setCli_firstname(firstname);
    client.setCli_lastname(lastname);
    client.setCli_address(address);
    client.setCli_postcode(postcode.toInt());
    client.setCli_city(city);
    client.setCli_rdv_date(rdv_date);
    client.setCli_priority(priority);
    client.setCli_rdv_duration(rdv_duration.toInt());
    client.setCli_tel(tel.toInt());
    client.setCli_comment(comment);
    // set resources id
    vector<int> v_res_id;
    QStringList res = res_string.split(';');
    for(int i = 0;i<res.size();i++)
    {
        QString id = res[i].split('.')[0];

        v_res_id.push_back(id.toInt());
    }
    qDebug()<<v_res_id;
    client.setCli_v_resources(v_res_id);
    clientDAO.insertClient(client);
    //qDebug()<<clientDAO.selectClientById(8).getCli_firstname();
    //qDebug()<<clientDAO.selectClientById(7).getCli_firstname();

}
