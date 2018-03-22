#include "planning.h"

Planning::Planning()
{

}

bool Planning::excuteAlgoPlanning(QDate date)
{
    int i =0;
    vector<Resource> v_r;
    vector<Appointment> v_app;
    clientController.getClientByDate(v_c, date);

    for(i = 0;i<v_c.size();i++)
    {

        // prepare appointment
        int app_i = 0;
        appointmentController.getAppointmentByClientId(v_c.at(i).getCli_id(),v_app);
        for(app_i = 0;app_i<v_app.size();app_i++)
        {
            v_c.at(i).getCli_v_resources().push_back(v_app.at(app_i).getApp_resource().getRes_id());
        }
        // get all resources
        getClientsResource(i,v_r);
        //for each client
        int j = 0;
        for(j = 0;j<v_r.size();j++)
        {
            // for each resource
            int total = v_c.at(i).getCli_rdv_duration()/v_c.at(i).getCli_v_resources().size();
            int cellNeed = total/15 + (total%15==0?0:1);
            int start = 0;
            if(j!=0)
            {
                start = v_r.at(j-1).resourceRDVInfo.maxIndex[i];
                if(v_r.at(j-1).resourceRDVInfo.availability[start]!=0)
                    start++;
            }

            int firstAva = findFirstAvailabile(start,cellNeed,v_r.at(j).resourceRDVInfo.availability);
            int k;
            for(k = firstAva;k<firstAva+cellNeed;k++)
            {
                if(total>=15)
                {
                    total-=15;
                    v_r.at(j).resourceRDVInfo.timeLine[k] = 15;
                }
                else{
                    v_r.at(j).resourceRDVInfo.timeLine[k] = total;
                }
                v_r.at(j).resourceRDVInfo.availability[k] = 1;
                v_r.at(j).resourceRDVInfo.maxIndex[i] = k;
            }

        }

    }
    return true;
}

void Planning::getClientsResource(int i, vector<Resource> &res)
{
    res.clear();
    int j = 0;
    for(j = 0;j<v_c.at(i).getCli_v_resources().size();j++)
    {
        res.push_back(resourceController.getResourceById(v_c.at(i).getCli_v_resources().at(j)));
    }
}

int Planning::findFirstAvailabile(int start,int cellNeed, int list[])
{
    int i = start;
    bool allzero;
    for(i  = start;i<50;i++)
    {
        allzero = true;
        if(list[i]==0)
        {
            int j = 0;
            for(j = i;j<i+cellNeed;j++)
            {
                if(list[j]!=0)
                {
                    allzero = false;
                }
            }
            if(allzero)
            {
                return i;
            }
        }
    }
    return -1;
}
int Planning::findFirstZero(int list[])
{
    int i = 0;
    for(i  = 0;i<50;i++)
    {
        if(list[i]==0)
        {
            return i;
        }
    }
    return -1;
}
