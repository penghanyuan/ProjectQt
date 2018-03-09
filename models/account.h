#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include "resource.h"

class Account
{
private:
    int acc_id;
    Resource acc_resource;
    QString acc_username;
    QString acc_password;

public:
    Account();
};

#endif // ACCOUNT_H
