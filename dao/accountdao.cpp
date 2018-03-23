#include "accountdao.h"

AccountDAO::AccountDAO()
{
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}


/**
 * @brief selectAccountByUsername
 * @param {QString} username the username of the account
 * @return {Account} get the account object who's username is as the username given.
 */
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


/**
 * @brief selectAccountByResourceId
 * @param {int} id resource id to select by
 * @return {Account} get the account object of this id.
 */
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


/**
 * @brief modifyAccount
 * @param {Account} account an account objet to be modified
 * @return {bool} return true if this operation was done correctly.
 */
bool AccountDAO::modifyAccount(Account account)
{
    QSqlQuery query(db);

    query.prepare("UPDATE TCompte "
                  "SET IdRessource = ? , Login = ? , MdP = ? WHERE Id = ?");

    query.addBindValue(account.getAcc_resource().getRes_id());
    query.addBindValue(account.getAcc_username());
    query.addBindValue(account.getAcc_password());
    query.addBindValue(account.getAcc_id());

    return query.exec();
}



/**
 * @brief deleteAccount
 * @param idRes resource id of this account
 * @return return true if this operation was done correctly.
 */
bool AccountDAO::deleteAccount(int idRes){
    QSqlQuery query(db);

    query.prepare("DELETE FROM TCompte WHERE IdRessource = ?");

    query.addBindValue(idRes);

    return query.exec();
}


/**
 * @brief insertAccount
 * @param acc a new account object who comes from the user input.
 * @return return true if this operation was done correctly.
 */
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
