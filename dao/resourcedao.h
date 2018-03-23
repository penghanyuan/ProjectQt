#ifndef RESOURCEDAO_H
#define RESOURCEDAO_H
#include "models/resource.h"
#include "models/account.h"
#include "models/appointment.h"
#include "connectionsql.h"
#include "dao/typedao.h"
#include "dao/accountdao.h"
#include "dao/appointmentdao.h"
#include <vector>
#include <QSqlQuery>
#include <QSqlDatabase>
using namespace std;
class ResourceDAO
{
private:
    Resource resource;
    QSqlDatabase db;
    AppointmentDAO appointmentDAO;
    AccountDAO accountDAO;
public:
    ResourceDAO();
    bool selectAllResources(vector<Resource>& resources);
    Resource selectResourceById(int id);
    bool insertResource(Resource resource);
    bool insertTechnician(Account account);
    bool modifyResource(Resource resource);
    bool modifyTechnician(Account account);
    bool deleteResource(int id);
    bool deleteTechnician(int id);
    int selectMaxId();
};

#endif // RESOURCEDAO_H
