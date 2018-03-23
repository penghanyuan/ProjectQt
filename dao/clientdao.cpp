#include "clientdao.h"

ClientDAO::ClientDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

/**
 * @brief ClientDAO::insertClient
 * @param cl
 * @return bool value if the operation is done correctly.
 */
bool ClientDAO::insertClient(Client &cl){

    QSqlQuery query(db);

    query.prepare("INSERT INTO TClient"
                  "(Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite)"
                  "VALUES ( :Nom, :Prenom, :Adresse, :Ville, :CP, :Commentaire, :Tel, :DateRdv, :DureeRdv, :Priorite)");


    query.bindValue(":Nom", cl.getCli_lastname());
    query.bindValue(":Prenom", cl.getCli_firstname());
    query.bindValue(":Adresse", cl.getCli_address());
    query.bindValue(":Ville", cl.getCli_city());
    query.bindValue(":CP", cl.getCli_postcode());
    query.bindValue(":DateRdv", cl.getCli_rdv_date());
    query.bindValue(":DureeRdv", cl.getCli_rdv_duration());
    query.bindValue(":Priorite", cl.getCli_priority());
    query.bindValue(":Commentaire", cl.getCli_comment());
    query.bindValue(":Tel", cl.getCli_tel());

    return query.exec();


}


/**
 * @brief ClientDAO::getClientInfo
 * @param query
 * @return A client obejct as a result by query
 */
Client ClientDAO::getClientInfo(QSqlQuery query){

    int id = query.value(0).toInt();
    QString lastname = query.value(1).toString();
    QString firstname = query.value(2).toString();
    QString address = query.value(3).toString();
    QString city = query.value(4).toString();
    int postcode = query.value(5).toInt();
    QString comment = query.value(6).toString();
    int tel = query.value(7).toInt();
    QDate dateRDV = query.value(8).toDate();
    int dureeRDV = query.value(9).toInt();
    int priority = query.value(10).toInt();

    Client c;
    c.setCli_id(id);
    c.setCli_lastname(lastname);
    c.setCli_firstname(firstname);
    c.setCli_address(address);
    c.setCli_city(city);
    c.setCli_postcode(postcode);
    c.setCli_comment(comment);
    c.setCli_tel(tel);
    c.setCli_rdv_date(dateRDV);
    c.setCli_rdv_duration(dureeRDV);
    c.setCli_priority(priority);

    return c;
}


/**
 * @brief ClientDAO::selectClientById
 * @param id
 * @return A client obejct with this id
 */
Client ClientDAO::selectClientById(int id)
{

    QSqlQuery query(db);

    query.prepare("SELECT * FROM TClient WHERE Id = ?");
    query.addBindValue(id);
    query.exec();

    query.next();
    return getClientInfo(query);

}

/**
 * @brief ClientDAO::selectClientListByLastname
 * @param value
 * @param clientList
 * @return bool value if the operation is done succesfully.
 */
bool ClientDAO::selectClientListByLastname(QString value, vector<Client> &clientList){

    QSqlQuery query(db);
    query.prepare("SELECT * FROM TClient WHERE Nom LIKE ?");
    query.addBindValue(value+"%");
    query.exec();

    while ( query.next() ) {

        clientList.push_back(getClientInfo(query));
    }
    if(!clientList.empty())
    {
        return true;
    }
    else
    {
        return false;
    }

}


/**
 * @brief ClientDAO::selectClientListByFirstname
 * @param value
 * @param clientList
 * @return bool value if the operation is done succesfully.
 */
bool ClientDAO::selectClientListByFirstname(QString value, vector<Client> &clientList){

    QSqlQuery query(db);
    query.prepare("SELECT * FROM TClient WHERE Prenom LIKE ?");
    query.addBindValue(value+"%");
    query.exec();

    while ( query.next() ) {

        clientList.push_back(getClientInfo(query));
    }
    if(!clientList.empty())
    {
        return true;
    }
    else
    {
        return false;
    }

}


/**
 * @brief ClientDAO::selectAllClients
 * @param clientList
 * @return bool value if the operation is done succesfully.
 */
bool ClientDAO::selectAllClients(vector<Client> &clientList)
{

    QSqlQuery query(db);
    query.prepare("SELECT * FROM TClient");
    query.exec();
    while ( query.next() ) {
        clientList.push_back(getClientInfo(query));
    }
    if(!clientList.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


/**
 * @brief ClientDAO::selectClientListByDate
 * @param clientList
 * @param rdvBeginDate
 * @param rdvEndDate
 * @return bool value if the operation is done succesfully.
 */
bool ClientDAO::selectClientListByDate(vector<Client> &clientList, QString rdvBeginDate, QString rdvEndDate){
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TClient WHERE DateRdv BETWEEN ? AND ?  ");

    query.addBindValue(rdvBeginDate);
    query.addBindValue(rdvEndDate);

    query.exec();

    while ( query.next() ) {

        clientList.push_back(getClientInfo(query));
    }
    if(!clientList.empty())
    {
        return true;
    }
    else
    {
        return false;
    }

}

/**
 * @brief ClientDAO::modifyClient
 * @param cl
 * @param id
 * @return bool value if the operation is done succesfully.
 */
bool ClientDAO::modifyClient(Client &cl, int id){

    QSqlQuery query(db);

    query.prepare("UPDATE TClient "
                  "SET Nom = ? , Prenom = ? , Adresse = ? ,Ville = ?, CP = ?, "
                  "Commenraire = ?, Tel =?, DateRdv = ?, DureeRdv = ?, Priorite = ? WHERE Id = ?");

    query.addBindValue(cl.getCli_lastname());
    query.addBindValue(cl.getCli_firstname());
    query.addBindValue(cl.getCli_address());
    query.addBindValue(cl.getCli_city());
    query.addBindValue(cl.getCli_postcode());
    query.addBindValue(cl.getCli_rdv_date());
    query.addBindValue(cl.getCli_rdv_duration());
    query.addBindValue(cl.getCli_priority());
    query.addBindValue(cl.getCli_comment());
    query.addBindValue(cl.getCli_tel());
    query.addBindValue(id);

    return query.exec();
}


/**
 * @brief ClientDAO::deleteClient
 * @param id
 * @return bool value if the operation is done succesfully.
 */
bool ClientDAO::deleteClient(int id){

    QSqlQuery query(db);

    query.prepare("DELETE FROM TClient WHERE Id = ?");

    query.addBindValue(id);



    return query.exec()&&appointmentDAO.deleteAppointmentByClientId(id);
}


/**
 * @brief ClientDAO::selectMaxId
 * @return the maximum id amont the clients
 */
int ClientDAO::selectMaxId()
{
    QSqlQuery query(db);
    QString strSqlText("SELECT max(Id) FROM TClient");
    query.prepare(strSqlText);
    query.exec();
    while ( query.next() ) {
        return query.value(0).toInt();
    }
}
