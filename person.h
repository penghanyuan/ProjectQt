#ifndef USER_H
#define USER_H
#include <QString>
#include <QDateTime>
class Person
{
private:
    QString u_username;
    QString u_password;
    QDateTime u_last_login_datetime;
public:
    Person();
    QDateTime getU_last_login_datetime() const;
    void setU_last_login_datetime(const QDateTime &value);
    QString getU_password() const;
    void setU_password(const QString &value);
    QString getU_username() const;
    void setU_username(const QString &value);
};

#endif // USER_H
