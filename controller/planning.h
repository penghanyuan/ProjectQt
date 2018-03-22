#ifndef PLANNING_H
#define PLANNING_H
#include <vector>
#include "models/client.h"
#include "models/resource.h"
#include "controller/clientcontroller.h"
#include "controller/resourcescontroller.h"
#include "controller/appointmentcontroller.h"
using namespace std;
class Planning
{
public:
    Planning();

    bool excuteAlgoPlanning(QDate date);

private:
    ClientController clientController;
    ResourcesController resourceController;
    AppointmentController appointmentController;
    vector<Client> v_c;
    int findFirstAvailabile(int start,int cellNeed, int list[]);
    int findFirstZero(int list[]);
    void getClientsResource(int i, vector<Resource> &res);
};

#endif // PLANNING_H
