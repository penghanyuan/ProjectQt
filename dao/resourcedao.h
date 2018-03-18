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
    bool insertResource(Resource resource);
    bool insertTechnician(Account account);
    bool modifyResource(Resource resource, int id);
    bool deleteResource(int id);

};

#endif // RESOURCEDAO_H
