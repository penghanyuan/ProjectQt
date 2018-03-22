#include "planning.h"

Planning::Planning()
{

}

bool Planning::excuteAlgoPlanning(vector<Client>&v_c)
{
    vector<Resource> v_r;
    int i =0;
    for(i = 0;i<v_c.size();i++)
    {
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
                start = v_r.at(j-1).getResourceRDVInfo().maxIndex[i];
                if(v_r.at(j-1).getResourceRDVInfo().availability[start]!=0)
                    start++;
            }

            int firstAva = findFirstAvailabile(start,cellNeed,v_r.at(j).getResourceRDVInfo().availability);
            int k;
            for(k = firstAva;k<firstAva+cellNeed;k++)
            {
                if(total>=15)
                {
                    total-=15;
                    v_r.at(j).getResourceRDVInfo().timeLine[k] = 15;
                }
                else{
                    v_r.at(j).getResourceRDVInfo().timeLine[k] = total;
                }
                v_r.at(j).getResourceRDVInfo().availability[k] = 1;
                v_r.at(j).getResourceRDVInfo().maxIndex[i] = k;
            }

        }

    }
}

int findFirstAvailabile(int start,int cellNeed, int list[])
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
int findFirstZero(int list[])
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
