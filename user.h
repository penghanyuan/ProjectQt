#ifndef USER_H
#define USER_H
#include <QString>

class User
{
private:
    QString u_username;
    QString u_password;
public:
    User();
    QString getUsername(){
        return u_username;
    }
    QString getPassword(){
        return u_password;
    }
    void setUsername(QString username){
        u_username = username;
    }
    void setPassword(QString password){
        u_password = password;
    }
};

#endif // USER_H
