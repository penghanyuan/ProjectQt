#include "resourcedao.h"

ResourceDAO::ResourceDAO()
{
    //C_INIT_BD::Creation_BD();
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();
}

bool ResourceDAO::selectAllResources(vector<Resource> &resources)
{
    TypeDAO typeDAO;
    QSqlQuery query(db);
    QString strSqlText("SELECT * FROM TRessource");
    query.prepare(strSqlText);
    query.exec();
    while ( query.next() ) {
        int id = query.value(0).toInt();
        QString lastname = query.value(1).toString();
        QString firstname = query.value(2).toString();
        int type_id = query.value(3).toInt();
        Type type = typeDAO.selectTypeById(type_id);
        Resource r;
        r.setRes_id(id);
        r.setRes_firstname(firstname);
        r.setRes_lastname(lastname);
        r.setRes_type(type);
        resources.push_back(r);
    }
    if(!resources.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
