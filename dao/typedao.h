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
    bool insertType(Type &type);
    Type selectTypeById(int id);
    bool selectAllType(vector<Type>& types);
    Type selectTypeByName(QString name);
};

#endif // TYPEDAO_H
