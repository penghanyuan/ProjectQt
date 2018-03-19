#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include "dao/accountdao.h"
#include <QString>
class AccountController
{
private:
    AccountDAO accountDAO;
public:
    AccountController();
    bool verifyLogin(QString username,QString password);
    bool addAccount(QString username,QString password, Resource resource);
    Account getAccountByResourceId(int res_id);
};

#endif // LOGINCONTROLLER_H
