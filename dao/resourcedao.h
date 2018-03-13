#ifndef RESOURCEDAO_H
#define RESOURCEDAO_H
#include "models/resource.h"
#include "models/account.h"
#include "connectionsql.h"
#include "dao/typedao.h"
#include "dao/accountdao.h"
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
    bool insertResource(Resource &resource);
    bool insertTechnician(Resource &resource, QString usr, QString pwd);
};

#endif // RESOURCEDAO_H
