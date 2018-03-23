#include "planning.h"
#include <iostream>
Planning::Planning()
{

}
/**
 * @brief Planning::excuteAlgoPlanning
 * @param date
 * @return
 */
bool Planning::excuteAlgoPlanning(QDate date)
{
    int i =0;
    //vector<Resource> v_r;

    clientController.getClientByDate(v_c, date);
    sort(v_c.begin(),v_c.end(),Planning::descend);
    // prepare appointment
    for(i = 0;i<v_c.size();i++)
    {

        int app_i = 0;
        vector<Appointment> v_app;
        appointmentController.getAppointmentByClientId(v_c.at(i).getCli_id(),v_app);
        for(app_i = 0;app_i<v_app.size();app_i++)
        {
            v_c.at(i).getCli_v_resources().push_back(v_app.at(app_i).getApp_resource().getRes_id());
        }
    }
    // get all resources
    getClientsResource();

    for(i = 0;i<v_c.size();i++)
    {
        //for each client
        int j = 0;
        QMap<int,Resource>::iterator qm_res_it;
        for(qm_res_it = m_r.begin();qm_res_it!=m_r.end();++qm_res_it)
        {
            if(!checkResNeeded(i,qm_res_it->getRes_id()))
                continue;
            // for each resource
            int total = v_c.at(i).getCli_rdv_duration()/v_c.at(i).getCli_v_resources().size();
            int cellNeed = total/15 + (total%15==0?0:1);
            int start = 0;
            if(j!=0)
            {
                start = qm_res_it->resourceRDVInfo.maxIndex[i];
                if(qm_res_it->resourceRDVInfo.availability[start]!=0)
                    start++;
            }

            int firstAva = findFirstAvailabile(start,cellNeed,qm_res_it->resourceRDVInfo.availability);
            int k;
            v_c.at(i).clientRDVInfo.startIndex.push_back(k);
            v_c.at(i).clientRDVInfo.cellNeeded.push_back(k);
            for(k = firstAva;k<firstAva+cellNeed;k++)
            {
                if(total>=15)
                {
                    total-=15;
                    // set time for resource
                    qm_res_it->resourceRDVInfo.timeLine[k] = 15;
                }
                else{
                     // set time for resource
                    qm_res_it->resourceRDVInfo.timeLine[k] = total;
                }
                qm_res_it->resourceRDVInfo.availability[k] = v_c.at(i).getCli_id();
                qm_res_it->resourceRDVInfo.maxIndex[i] = k;
            }
        }

    }
    return true;
}

/**
 * @brief Planning::getClientsResource
 */
void Planning::getClientsResource()
{
    int i = 0;
    int j = 0;
    for(i = 0;i<v_c.size();i++)
    {
        for(j = 0;j<v_c.at(i).getCli_v_resources().size();j++)
        {
            int resid = v_c.at(i).getCli_v_resources().at(j);
            m_r.insert(resid,resourceController.getResourceById(resid));
        }
    }

}

/**
 * @brief Planning::checkResNeeded
 * @param i
 * @param id
 * @return
 */
bool Planning::checkResNeeded(int i, int id)
{
    for(int j = 0;j<v_c.at(i).getCli_v_resources().size();j++)
    {
        if(v_c.at(i).getCli_v_resources()[j]==id)
            return true;
    }
    return false;
}


/**
 * @brief Planning::getPlanning
 * @param out
 */
void Planning::getPlanning(QTextStream &out)
{
    QMap<int,Resource>::iterator m_it;

    for(m_it = m_r.begin();m_it!=m_r.end();++m_it)
    {
        // for each resource
        out<<"Resource:"<<m_it->getRes_id()<<", "<<m_it->getRes_firstname()+" "+m_it->getRes_lastname()<<"\n";
        out<<"Time\t"<<"\n";
        int start = 7;
        for(int i = 0;i<50;i++)
        {
            if((i*15)%60==0)
                start++;
            if(m_it->resourceRDVInfo.availability[i]!=0)
            {
                out<<QObject::tr("%1:%2, Client %3, duration: %4").arg(start).arg((i*15)%60).arg(m_it->resourceRDVInfo.availability[i]).arg(m_it->resourceRDVInfo.timeLine[i]);
                out<<"\n";
            }

        }
        out<<"================"<<"\n";
    }
}


/**
 * @brief Planning::saveFile
 * @param filename
 * @return
 */
bool Planning::saveFile(QString filename)
{


    QFile data(filename);
    if (data.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&data);
        getPlanning(out);
    }
}

/**
 * @brief Planning::findFirstAvailabile
 * @param start
 * @param cellNeed
 * @param list
 * @return
 */
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

/**
 * @brief Planning::findFirstZero
 * @param list
 * @return
 */
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
