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
    int getAcc_id() const;
    void setAcc_id(int value);
    Resource getAcc_resource() const;
    void setAcc_resource(const Resource &value);
    QString getAcc_username() const;
    void setAcc_username(const QString &value);
    QString getAcc_password() const;
    void setAcc_password(const QString &value);
};

#endif // ACCOUNT_H
