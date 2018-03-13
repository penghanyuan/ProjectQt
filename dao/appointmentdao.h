#ifndef APPOINTMENTDAO_H
#define APPOINTMENTDAO_H
#include "connectionsql.h"
#include "models/client.h"
#include "models/resource.h"
#include <QSqlQuery>
#include <QSqlDatabase>

class appointmentDAO
{
public:
    appointmentDAO();
    bool insertAppointment(Client &client, Resource &resource);

};

#endif // APPOINTMENTDAO_H
