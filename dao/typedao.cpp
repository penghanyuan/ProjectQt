#include "typedao.h"

TypeDAO::TypeDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

/**
 * @brief TypeDAO::selectTypeById
 * @param id
 * @return
 */
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


/**
 * @brief TypeDAO::selectAllType
 * @param types
 * @return
 */
bool TypeDAO::selectAllType(vector<Type> &types)
{
    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TType order by Id");
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


/**
 * @brief TypeDAO::insertType
 * @param type
 * @return
 */
bool TypeDAO::insertType(Type &type){
    
    QSqlQuery query(db);
    
    QString strSqlCheckExist("SELECT * FROM TType WHERE Label = ? ");
    query.addBindValue(type.getType_label());
    query.prepare(strSqlCheckExist);
    query.exec();
    if(!query.next()){
        QString strSqlInsertText("INSERT INTO TType"
                                 "(Label) "
                                 "VALUES (:Label)");
        query.prepare(strSqlInsertText);
        query.bindValue(":Label", type.getType_label());
        
        query.exec();
    }
    
}
