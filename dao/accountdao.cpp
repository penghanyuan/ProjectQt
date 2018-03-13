#include "accountdao.h"

AccountDAO::AccountDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

bool AccountDAO::insertAccount(Resource &res, QString usr, QString pwd){

    QSqlQuery query(db);

    QString strSqlCheckExist("SELECT * FROM TCompte WHERE Login = ? ");
    query.addBindValue(usr);
    query.prepare(strSqlCheckExist);
    query.exec();
    if(!query){

        QString strSqlInsertText("INSERT INTO TCompte"
                                 "(IdRessource, Login, Mdp) "
                                 "VALUES (:IdRessource, :Login, :Mdp)");
        query.prepare(strSqlInsertText);
        query.bindValue(":IdRessource", res.getRes_id());
        query.bindValue(":Login", usr);
        query.bindValue(":Mdp", pwd);

        query.exec();
    }

}
