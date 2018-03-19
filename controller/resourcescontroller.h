#ifndef RESOURCESCONTROLLER_H
#define RESOURCESCONTROLLER_H
#include <iostream>
#include <vector>
#include <map>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "models/resource.h"
#include "dao/resourcedao.h"
using namespace std;
class ResourcesController
{
private:
    ResourceDAO resourceDAO;
    Resource resource;
    AccountDAO accountDAO;

    // functions
    void makeResource(QString lastname,QString firstname,QString type);
public:
    ResourcesController();
    bool getAllResources(vector<Resource>& resources);
    bool addResource(QString lastname,QString firstname,QString type);
    bool addTechnicien(QString lastname,QString firstname,QString type,QString username, QString password);
    Resource getResourceById(int id);
    bool modifyResource(int id, QString lastname,QString firstname,QString type);
    bool modifyTechnicien(int id, QString lastname,QString firstname,QString type,QString username, QString password);
};

#endif // RESOURCESCONTROLLER_H
