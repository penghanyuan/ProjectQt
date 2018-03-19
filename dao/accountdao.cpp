#include "accountdao.h"

AccountDAO::AccountDAO()
{
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

Account AccountDAO::selectAccountByUsername(QString username)
{
    ResourceDAO resDAO;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TCompte WHERE Login = ? ");
    query.addBindValue(username);
    query.exec();
    Account a;
    while ( query.next() ) {
        int id = query.value(0).toInt();
        int res_id = query.value(1).toInt();
        QString username = query.value(2).toString();
        QString password = query.value(3).toString();
        Resource res = resDAO.selectResourceById(res_id);
        a.setAcc_id(id);
        a.setAcc_resource(res);
        a.setAcc_username(username);
        a.setAcc_password(password);
    }
    return a;
}

Account AccountDAO::selectAccountByResourceId(int id)
{
    ResourceDAO resDAO;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TCompte WHERE IdRessource = ? ");
    query.addBindValue(id);
    query.exec();
    Account a;
    while ( query.next() ) {
        int id = query.value(0).toInt();
        int res_id = query.value(1).toInt();
        QString username = query.value(2).toString();
        QString password = query.value(3).toString();
        Resource res = resDAO.selectResourceById(res_id);
        a.setAcc_id(id);
        a.setAcc_resource(res);
        a.setAcc_username(username);
        a.setAcc_password(password);
    }
    return a;
}

bool AccountDAO::modifyAccount(Account account)
{

}

bool AccountDAO::insertAccount(Account acc){
    
    QSqlQuery query(db);
    
    query.prepare("SELECT * FROM TCompte WHERE Login = ? ");
    query.addBindValue(acc.getAcc_username());
    query.exec();
    if(!query.next()){
        
        QString strSqlInsertText("INSERT INTO TCompte"
                                 "(IdRessource, Login, Mdp) "
                                 "VALUES (:IdRessource, :Login, :Mdp)");
        query.prepare(strSqlInsertText);
        query.bindValue(":IdRessource", acc.getAcc_resource().getRes_id());
        query.bindValue(":Login", acc.getAcc_username());
        query.bindValue(":Mdp", acc.getAcc_password());
        
        return query.exec();
    }
    
}
