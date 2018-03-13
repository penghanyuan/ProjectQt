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
};

#endif // LOGINCONTROLLER_H
