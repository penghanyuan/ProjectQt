#include "resourcedao.h"

ResourceDAO::ResourceDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}


bool ResourceDAO::insertResource(Resource res){

    QSqlQuery query(db);

    QString strSqlInsertText("INSERT INTO TRessource"
                             "(Nom, Prenom, IdType) "
                             "VALUES (:Nom, :Prenom, :IdType)");
    query.prepare(strSqlInsertText);
    query.bindValue(":Nom", res.getRes_lastname());
    query.bindValue(":Prenom", res.getRes_firstname());
    query.bindValue(":IdType", res.getRes_type().getType_id());

    return query.exec();

}

bool ResourceDAO::insertTechnician(Account ac){

    QSqlQuery query(db);

    insertResource(ac.getAcc_resource());

    AccountDAO accDao;
    return accDao.insertAccount(ac);

}


bool ResourceDAO::selectAllResources(vector<Resource> &resources){

    TypeDAO typeDAO;
    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TRessource");
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

Resource ResourceDAO::selectResourceById(int id)
{
    TypeDAO typeDAO;
    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TRessource where Id = ?");
    query.prepare(strSqlText);
    query.addBindValue(id);
    query.exec();
    Resource r;
    while ( query.next() ) {
        int id = query.value(0).toInt();
        QString lastname = query.value(1).toString();
        QString firstname = query.value(2).toString();
        int type_id = query.value(3).toInt();
        Type type = typeDAO.selectTypeById(type_id);
        r.setRes_id(id);
        r.setRes_firstname(firstname);
        r.setRes_lastname(lastname);
        r.setRes_type(type);
    }
    return r;
}




bool ResourceDAO::modifyResource(Resource res){

    QSqlQuery query(db);

    query.prepare("UPDATE TRessource "
                  "SET Nom = ? , Prenom = ? , IdType = ? "
                  "WHERE Id = ? ");

    query.addBindValue(res.getRes_lastname());
    query.addBindValue(res.getRes_firstname());
    query.addBindValue(res.getRes_type().getType_id());
    query.addBindValue(res.getRes_id());

    return query.exec();
}

bool ResourceDAO::deleteResource(int id){

    QSqlQuery query(db);

    query.prepare("DELETE FROM TRessource WHERE Id = ?");

    query.addBindValue(id);

    return query.exec();
}

int ResourceDAO::selectMaxId()
{
    QSqlQuery query(db);
    QString strSqlText("SELECT max(Id) FROM TRessource");
    query.prepare(strSqlText);
    query.exec();
    while ( query.next() ) {
        return query.value(0).toInt();
    }
}
