#ifndef PLANNING_H
#define PLANNING_H
#include <vector>
#include <QMap>
#include <QFile>
#include <QFileDialog>
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

    bool saveFile(QString filename);

private:
    static bool descend(Client &c1,Client &c2){
        int i = c1.getCli_priority()*100+c1.getCli_v_resources().size()*10+c1.getCli_rdv_duration();
        int j = c2.getCli_priority()*100+c2.getCli_v_resources().size()*10+c2.getCli_rdv_duration();
        return (i>j);
    }
    ClientController clientController;
    ResourcesController resourceController;
    AppointmentController appointmentController;
    vector<Client> v_c;
    QMap<int,Resource> m_r;
    int findFirstAvailabile(int start,int cellNeed, int list[]);
    int findFirstZero(int list[]);
    void getClientsResource();
    bool checkResNeeded(int i,int id);
    void getPlanning(QTextStream &out);
};

#endif // PLANNING_H
