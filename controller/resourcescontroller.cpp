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
