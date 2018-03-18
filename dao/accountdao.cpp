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
    QString strSqlText("SELECT * FROM TCompte");
    query.prepare(strSqlText);
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
