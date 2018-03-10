#ifndef RESOURCEDAO_H
#define RESOURCEDAO_H
#include "models/resource.h"
#include "connectionsql.h"
#include "dao/typedao.h"
#include <vector>
#include <QSqlQuery>
#include <QSqlDatabase>
using namespace std;
class ResourceDAO
{
private:
    Resource resource;
    QSqlDatabase db;
public:
    ResourceDAO();
    bool selectAllResources(vector<Resource>& resources);
    Resource selectResourceById(int id);
    bool insertResource();
};

#endif // RESOURCEDAO_H
