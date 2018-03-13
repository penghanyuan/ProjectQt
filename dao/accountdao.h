#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H
#include "models/account.h"
#include "connectionsql.h"
#include "dao/resourcedao.h"
#include <QSqlQuery>
#include <QSqlDatabase>

class AccountDAO
{
private:
    Account account;
    QSqlDatabase db;
public:
    AccountDAO();
    Account selectAccountByUsername(QString username);
};

#endif // ACCOUNTDAO_H
