#include "person.h"

QDateTime Person::getU_last_login_datetime() const
{
    return u_last_login_datetime;
}

void Person::setU_last_login_datetime(const QDateTime &value)
{
    u_last_login_datetime = value;
}

QString Person::getU_password() const
{
    return u_password;
}

void Person::setU_password(const QString &value)
{
    u_password = value;
}

QString Person::getU_username() const
{
    return u_username;
}

void Person::setU_username(const QString &value)
{
    u_username = value;
}

Person::Person()
{

}
