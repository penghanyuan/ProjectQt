#include "appointmentdao.h"

appointmentDAO::appointmentDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

bool appointmentDAO::insertAppointment(Client &cl, Resource &res){

    QSqlQuery query(db);

    QString strSqlInsertText("INSERT INTO TRdv"
                             "(IdClient, IdRessource) "
                             "VALUES (:IdClient, :IdRessource)");
    query.prepare(strSqlInsertText);
    query.bindValue(":IdRessource", res.getRes_id());
    query.bindValue(":IdClient", cl.getCli_id());

    query.exec();
}
