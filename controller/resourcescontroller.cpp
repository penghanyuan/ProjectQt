#include "resourcescontroller.h"

ResourcesController::ResourcesController()
{

}

bool ResourcesController::getAllResources(vector<Resource> &resources)
{

    if(resourceDAO.selectAllResources(resources))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ResourcesController::addResource(QString lastname, QString firstname, QString type)
{
    makeResource(lastname,firstname,type);
    bool result = resourceDAO.insertResource(this->resource);
    this->resource.setRes_id(resourceDAO.selectMaxId());
    return result;
}

bool ResourcesController::addTechnicien(QString lastname, QString firstname, QString type, QString username, QString password)
{
    addResource(lastname,firstname,type);
    Account account;
    account.setAcc_resource(this->resource);
    account.setAcc_username(username);
    account.setAcc_password(password);

    return accountDAO.insertAccount(account);
}

Resource ResourcesController::getResourceById(int id)
{
    return resourceDAO.selectResourceById(id);
}

bool ResourcesController::modifyResource(int id, QString lastname, QString firstname, QString type)
{
    makeResource(lastname,firstname,type);
    this->resource.setRes_id(id);
    return resourceDAO.modifyResource(resource);
}

bool ResourcesController::modifyTechnicien(int id, QString lastname, QString firstname, QString type, QString username, QString password)
{
    modifyResource(id,lastname,firstname,type);
    Account account = accountDAO.selectAccountByResourceId(id);
    account.setAcc_username(username);
    account.setAcc_password(password);
    accountDAO.modifyAccount(account);
}

bool ResourcesController::deleteResource(int id)
{
    return resourceDAO.deleteResource(id);
}

void ResourcesController::makeResource(QString lastname, QString firstname, QString type)
{

    this->resource.setRes_firstname(firstname);
    this->resource.setRes_lastname(lastname);
    Type res_type;
    int type_id = type.split(".")[0].toInt();
    res_type.setType_id(type_id);
    res_type.setType_label(type.split(".")[1]);
    this->resource.setRes_type(res_type);
}
