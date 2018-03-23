#include "appointmentcontroller.h"

AppointmentController::AppointmentController()
{

}
/**
 * @brief AppointmentController::addAppointment
 * @param client_id
 * @param res_id
 * @return
 */
bool AppointmentController::addAppointment(int client_id, int res_id)
{
    Resource resource;
    resource.setRes_id(res_id);
    Client client;
    client.setCli_id(client_id);
    return appointmentDAO.insertAppointment(client,resource);
}

/**
 * @brief AppointmentController::getAppointmentByClientId
 * @param cli_id
 * @param v_app
 */
void AppointmentController::getAppointmentByClientId(int cli_id, vector<Appointment> &v_app)
{
    appointmentDAO.selectAppointmentByClientID(cli_id,v_app);
}


/**
 * @brief AppointmentController::deleteAppointmentByClientId
 * @param cli_id
 * @return
 */
bool AppointmentController::deleteAppointmentByClientId(int cli_id)
{
    return appointmentDAO.deleteAppointmentByClientId(cli_id);
}
