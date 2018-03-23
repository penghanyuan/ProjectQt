#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H
#include "models/account.h"
#include "connectionsql.h"

#include <QSqlQuery>
#include <QSqlDatabase>

class AccountDAO
{
private:
    Account account;
    QSqlDatabase db;
public:
    AccountDAO();
    bool insertAccount(Account acc);
    Account selectAccountByUsername(QString username);
    Account selectAccountByResourceId(int id);
    bool modifyAccount(Account account);
    bool deleteAccount(int idRes);
};

#endif // ACCOUNTDAO_H
