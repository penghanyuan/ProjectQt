#include "resourcescontroller.h"

ResourcesController::ResourcesController()
{

}

bool ResourcesController::getAllResources(vector<QStandardItem *> &qsi_resources)
{
    vector<Resource> resources;
    resourceDAO.selectAllResources(resources);
    for(int i = 0;i<resources.size();i++)
    {
        cout<<resources.at(i).getRes_firstname().toStdString()<<endl;
    }
}
