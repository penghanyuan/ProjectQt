#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QString>
class LoginController
{
public:
    LoginController();
    bool verifyLogin(QString username,QString password);
};

#endif // LOGINCONTROLLER_H
