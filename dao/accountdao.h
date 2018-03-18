#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H
#include "models/account.h"
#include "connectionsql.h"
#include <QSqlQuery>
#include <QSqlDatabase>

class AccountDAO
{
private:
    QSqlDatabase db;

public:
    AccountDAO();
    bool insertAccount(Account &account);
};

#endif // ACCOUNTDAO_H
