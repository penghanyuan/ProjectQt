#include "appointmentcontroller.h"

AppointmentController::AppointmentController()
{

}

bool AppointmentController::addAppointment(int client_id, int res_id)
{
    Resource resource;
    resource.setRes_id(res_id);
    Client client;
    client.setCli_id(client_id);
    return appointmentDAO.insertAppointment(client,resource);
}

void AppointmentController::getAppointmentByClientId(int cli_id, vector<Appointment> &v_app)
{
    appointmentDAO.selectAppointmentByClientID(cli_id,v_app);
}
