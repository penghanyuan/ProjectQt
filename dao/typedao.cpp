#include "typedao.h"

TypeDAO::TypeDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}


bool TypeDAO::insertType(QString label){

    QSqlQuery query(db);

    QString strSqlCheckExist("SELECT * FROM TType WHERE Label = ? ");
    query.addBindValue(label);
    query.prepare(strSqlCheckExist);
    query.exec();
    if(!query){
        QString strSqlInsertText("INSERT INTO TType"
                                 "(Label) "
                                 "VALUES (:Label)");
        query.prepare(strSqlInsertText);
        query.bindValue(":Label", label);

        query.exec();
    }

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
