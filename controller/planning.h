#ifndef PLANNING_H
#define PLANNING_H
#include <vector>
#include "models/client.h"
#include "models/resource.h"
using namespace std;
class Planning
{
public:
    Planning();

    bool excuteAlgoPlanning(vector<Client>&clients);

private:
    int findFirstAvailabile(int start,int cellNeed, int list[]);
    int findFirstZero(int list[]);
};

#endif // PLANNING_H
