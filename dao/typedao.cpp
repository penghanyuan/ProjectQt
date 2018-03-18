#include "typedao.h"

TypeDAO::TypeDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

Type TypeDAO::selectTypeById(int id)
{
    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TType where Id = ?");
    query.prepare(strSqlText);
    query.addBindValue(id);
    query.exec();
    Type type;
    while ( query.next() ) {
        int id = query.value(0).toInt();
        QString label = query.value(1).toString();
        type.setType_id(id);
        type.setType_label(label);
    }
    return type;

}

bool TypeDAO::selectAllType(vector<Type> &types)
{
    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TType");
    query.prepare(strSqlText);
    query.exec();
    while ( query.next() ) {
        int id = query.value(0).toInt();
        QString label = query.value(1).toString();
        Type type;
        type.setType_id(id);
        type.setType_label(label);
        types.push_back(type);
    }
    if(!types.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
