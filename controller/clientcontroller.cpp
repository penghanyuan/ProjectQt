#include "clientcontroller.h"
#include <QDebug>
ClientController::ClientController()
{

}
/**
 * Add a client with all the informations collected from the user input
 * @brief ClientController::addClient
 * @param lastname
 * @param firstname
 * @param address
 * @param city
 * @param postcode
 * @param tel
 * @param comment
 * @param rdv_date
 * @param rdv_duration
 * @param res_string
 * @param priority
 * @return
 */
bool ClientController::addClient(QString lastname, QString firstname, QString address, QString city, QString postcode, QString tel, QString comment, QDate rdv_date, QString rdv_duration, QString res_string, int priority)
{
    bool result;
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
    //insert client
    clientDAO.insertClient(client);
    int client_id = clientDAO.selectMaxId();
    // set resources id
    vector<int> v_res_id;
    QStringList res = res_string.split(';');
    for(int i = 0;i<res.size();i++)
    {
        QString res_id = res[i].split('.')[0];
        v_res_id.push_back(res_id.toInt());
        result = appointmentController.addAppointment(client_id,res_id.toInt());
    }
    client.setCli_v_resources(v_res_id);
    return result;
    //qDebug()<<clientDAO.selectClientById(8).getCli_firstname();
    //qDebug()<<clientDAO.selectClientById(7).getCli_firstname();

}


/**
 * @brief ClientController::getAllClient
 * @param clients
 */
void ClientController::getAllClient(vector<Client> &clients)
{
    clientDAO.selectAllClients(clients);
}

/**
 * @brief ClientController::getClientByFirstName
 * @param clients
 * @param firstname
 */
void ClientController::getClientByFirstName(vector<Client> &clients, QString firstname)
{
    clientDAO.selectClientListByFirstname(firstname,clients);
}

/**
 * @brief ClientController::getClientByDate
 * @param clients
 * @param s_dateRdv
 */
void ClientController::getClientByDate(vector<Client> &clients, QDate s_dateRdv)
{
    QString fil_date_plan = QObject::tr("%1").arg(s_dateRdv.toString("yyyy-MM-dd"));
    clientDAO.selectClientListByDate(clients, fil_date_plan, fil_date_plan);
}
