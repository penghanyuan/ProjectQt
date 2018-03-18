#include "clientdao.h"

ClientDAO::ClientDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

void ClientDAO::insertClient(Client &cl){

    QSqlQuery query(db);

    query.prepare("INSERT INTO TClient(Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite) VALUES ( :Nom, :Prenom, :Adresse, :Ville, :CP, :Commentaire, :Tel, :DateRdv, :DureeRdv, :Priorite)");

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

    query.exec();


}


Client ClientDAO::selectClientById(int id)
{

    QSqlQuery query(db);

    query.prepare("SELECT * FROM TClient WHERE Id = ?");
    query.addBindValue(id);
    query.exec();

    query.next();
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


bool ClientDAO::selectClientListByLastname(QString value, vector<Client> &clientList){

    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TClient WHERE Nom LIKE ?");
    query.addBindValue(value+"%");

    query.prepare(strSqlText);
    query.exec();
    while ( query.next() ) {
        int id = query.value(0).toInt();
        QString lastname = query.value(1).toString();
        QString firstname = query.value(2).toString();

//        QString address = query.value(3).toString();
//        QString city = query.value(4).toString();
//        int postcode = query.value(5).toInt();
//        QString comment = query.value(6).toString();
//        int tel = query.value(7).toInt();
//        QDate dateRDV = query.value(8).toDate();
//        int dureeRDV = query.value(9).toInt();
//        int priority = query.value(10).toInt();

        Client c;
        c.setCli_id(id);
        c.setCli_lastname(lastname);
        c.setCli_firstname(firstname);
//        c.setCli_address(address);
//        c.setCli_city(city);
//        c.setCli_postcode(postcode);
//        c.setCli_comment(comment);
//        c.setCli_tel(tel);
//        c.setCli_rdv_date(dateRDV);
//        c.setCli_rdv_duration(dureeRDV);
//        c.setCli_priority(priority);


        clientList.push_back(c);
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


