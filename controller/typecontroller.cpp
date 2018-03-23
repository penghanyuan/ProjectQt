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

Type TypeController::getTypeById(int id)
{
    return typeDAO.selectTypeById(id);
}
