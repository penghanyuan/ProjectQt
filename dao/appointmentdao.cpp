#include "appointmentdao.h"

AppointmentDAO::AppointmentDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

bool AppointmentDAO::insertAppointment(Client &cl, Resource &res){

    QSqlQuery query(db);

    query.prepare("INSERT INTO TRdv"
                             "(IdClient, IdRessource) "
                             "VALUES (:IdClient, :IdRessource)");
    query.bindValue(":IdRessource", res.getRes_id());
    query.bindValue(":IdClient", cl.getCli_id());

    query.exec();
}

void AppointmentDAO::selectAppointmentByClientID(int id,vector<Appointment>&v_app)
{
    QSqlQuery query(db);

    query.prepare("SELECT * FROM TRdv WHERE IdClient = ?");
    query.addBindValue(id);
    query.exec();
    ResourceDAO resDAO;
    while(query.next())
    {
        Appointment appointment;
        appointment.setApp_id(query.value(0).toInt());
        appointment.setApp_resource(resDAO.selectResourceById(query.value(2).toInt()));
        v_app.push_back(appointment);
    }


}

bool AppointmentDAO::deleteAppointmentByClientId(int cli_id)
{
    QSqlQuery query(db);

    query.prepare("DELETE FROM TRdv WHERE IdClient = ?");

    query.addBindValue(cli_id);

    return query.exec();
}
