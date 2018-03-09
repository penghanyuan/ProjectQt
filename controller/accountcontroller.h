#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QString>
class AccountController
{
public:
    AccountController();
    bool verifyLogin(QString username,QString password);
};

#endif // LOGINCONTROLLER_H
