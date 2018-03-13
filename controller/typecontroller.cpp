#include "typecontroller.h"

TypeController::TypeController()
{

}

bool TypeController::getAllType(vector<Type> &types)
{
    if(typeDAO.selectAllType(types))
        return true;
    else
        return false;
}
