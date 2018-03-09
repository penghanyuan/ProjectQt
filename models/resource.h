#ifndef USER_H
#define USER_H
#include <QString>
#include <QDateTime>
#include "type.h"
class Resource
{
private:
    int res_id;
    QString res_firstname;
    QString res_lastname;
    Type res_type;
public:
    Resource();
    int getRes_id() const;
    void setRes_id(int value);
    QString getRes_firstname() const;
    void setRes_firstname(const QString &value);
    QString getRes_lastname() const;
    void setRes_lastname(const QString &value);
    Type getRes_type() const;
    void setRes_type(const Type &value);
};

#endif // USER_H
