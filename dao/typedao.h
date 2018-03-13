#ifndef TYPEDAO_H
#define TYPEDAO_H
#include "models/type.h"
#include "connectionsql.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <vector>
using namespace std;
class TypeDAO
{
private:
    Type type;
    QSqlDatabase db;
public:
    TypeDAO();
    Type selectTypeById(int id);
    bool selectAllType(vector<Type>& types);
};

#endif // TYPEDAO_H
