#ifndef TYPEDAO_H
#define TYPEDAO_H
#include "models/type.h"
#include "connectionsql.h"
#include <QSqlQuery>
#include <QSqlDatabase>
class TypeDAO
{
private:
    Type type;
    QSqlDatabase db;
public:
    TypeDAO();
    Type selectTypeById(int id);
};

#endif // TYPEDAO_H
