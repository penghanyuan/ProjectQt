#include "appointment.h"

int Appointment::getApp_id() const
{
    return app_id;
}

void Appointment::setApp_id(int value)
{
    app_id = value;
}

Client Appointment::getApp_client() const
{
    return app_client;
}

void Appointment::setApp_client(const Client &value)
{
    app_client = value;
}

Resource Appointment::getApp_resource() const
{
    return app_resource;
}

void Appointment::setApp_resource(const Resource &value)
{
    app_resource = value;
}

Appointment::Appointment()
{
    
}
