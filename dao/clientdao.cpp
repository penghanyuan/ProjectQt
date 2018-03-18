#include "clientdao.h"

ClientDAO::ClientDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

bool ClientDAO::insertClient(Client &cl){

    QSqlQuery query(db);

    QString lastname = cl.getCli_lastname();
    QString firstname = cl.getCli_firstname();
    QString address = cl.getCli_address();
    QString city = cl.getCli_city();
    int postcode = cl.getCli_postcode();
    QDate rdvDate = cl.getCli_rdv_date();
    int rdvDuration = cl.getCli_rdv_duration();
    int priority = cl.getCli_priority();

    /*-- verification of required options.--*/
    while(lastname && firstname && address && city && postcode && rdvDate && rdvDuration && priority ){

        QString strSqlInsertText("INSERT INTO TClient"
                                 "(Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite) "
                                 "VALUES (:Nom, :Prenom, :Adresse, :Ville, :CP, :Commentaire, :Tel, :DateRdv, :DureeRdv, :Priorite)");
        query.prepare(strSqlInsertText);

        query.bindValue(":Nom", lastname);
        query.bindValue(":Prenom", firstname);
        query.bindValue(":Adresse", address);
        query.bindValue(":Ville", city);
        query.bindValue(":CP", postcode);
        query.bindValue(":DateRdv", rdvDate);
        query.bindValue(":DureeRdv", rdvDuration);
        query.bindValue(":Priorite", priority);
        query.bindValue(":Commentaire", cl.getCli_comment());
        query.bindValue(":Tel", cl.getCli_tel());
    }


    query.exec();

//    QSqlQuery query;
//    query.prepare("INSERT INTO T_STUDENT (name,age) VALUES (?,?)");
//    query.addBindValue(cl.getCli_id());
//    query.
//    query.bindValue(cl.getCli_firstname());
//    query.exec();
}


Client ClientDAO::selectClientById(int id)
{

    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TClient WHERE TClient.Id = ? ");
    query.addBindValue(id);
    query.prepare(strSqlText);
    query.exec();

        int id = query.value(0).toInt();
        QString lastname = query.value(1).toString();
        QString firstname = query.value(2).toString();
        QString address = query.value(3).toString();
        QString city = query.value(4).toString();
        int postcode = query.value(5).toInt();
        QString comment = query.value(6).toString();
        int tel = query.value(7).toInt();
        QDate dateRDV = query.value(9).toInt();
        int dureeRDV = query.value(10).toInt();
        int priority = query.value(8).toDate();

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

        //or we can set the values directement...

    if(!c.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


Client ClientDAO::selectClientListByLastname(QString lastname){

    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TClient WHERE Nom = ");
    query.prepare(strSqlText);
    query.exec();
    while ( query.next() ) {
        int id = query.value(0).toInt();
        QString lastname = query.value(1).toString();
        QString firstname = query.value(2).toString();
        int type_id = query.value(3).toInt();
        Type type = typeDAO.selectTypeById(type_id);
        Resource r;
        r.setRes_id(id);
        r.setRes_firstname(firstname);
        r.setRes_lastname(lastname);
        r.setRes_type(type);
        resources.push_back(r);
    }
    if(!resources.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
