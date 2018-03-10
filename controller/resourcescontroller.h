#ifndef RESOURCESCONTROLLER_H
#define RESOURCESCONTROLLER_H
#include <iostream>
#include <vector>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "models/resource.h"
#include "dao/resourcedao.h"
using namespace std;
class ResourcesController
{
private:
    ResourceDAO resourceDAO;
public:
    ResourcesController();
    bool getAllResources(vector<QStandardItem*>& resources);

};

#endif // RESOURCESCONTROLLER_H
