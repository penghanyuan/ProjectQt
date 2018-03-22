#include "resource.h"


int Resource::getRes_id() const
{
    return res_id;
}

void Resource::setRes_id(int value)
{
    res_id = value;
}

QString Resource::getRes_firstname() const
{
    return res_firstname;
}

void Resource::setRes_firstname(const QString &value)
{
    res_firstname = value;
}

QString Resource::getRes_lastname() const
{
    return res_lastname;
}

void Resource::setRes_lastname(const QString &value)
{
    res_lastname = value;
}

Type Resource::getRes_type() const
{
    return res_type;
}

void Resource::setRes_type(const Type &value)
{
    res_type = value;
}

ResourceRDVInfo Resource::getResourceRDVInfo() const
{
    return resourceRDVInfo;
}

void Resource::setResourceRDVInfo(const ResourceRDVInfo &value)
{
    resourceRDVInfo = value;
}

Resource::Resource()
{
    
}
