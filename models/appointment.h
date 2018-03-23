#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>
#include "client.h"
#include "resource.h"

using namespace std;
class Appointment
{
private:
    int app_id;
    Client app_client;
    Resource app_resource;
public:
    Appointment();
    int getApp_id() const;
    void setApp_id(int value);
    Client getApp_client() const;
    void setApp_client(const Client &value);
    Resource getApp_resource() const;
    void setApp_resource(const Resource &value);
};

#endif // APPOINTMENT_H
