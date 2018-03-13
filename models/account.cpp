#include "account.h"

int Account::getAcc_id() const
{
    return acc_id;
}

void Account::setAcc_id(int value)
{
    acc_id = value;
}

Resource Account::getAcc_resource() const
{
    return acc_resource;
}

void Account::setAcc_resource(const Resource &value)
{
    acc_resource = value;
}

QString Account::getAcc_username() const
{
    return acc_username;
}

void Account::setAcc_username(const QString &value)
{
    acc_username = value;
}

QString Account::getAcc_password() const
{
    return acc_password;
}

void Account::setAcc_password(const QString &value)
{
    acc_password = value;
}

Account::Account()
{
    
}
