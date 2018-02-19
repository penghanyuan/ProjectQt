#ifndef CLIENT_H
#define CLIENT_H
#include <QString>

class Client
{
private:
    int cli_id;
    QString cli_lastname;
    QString cli_firstname;
    QString cli_address;
    QString cli_city;
    QString cli_postcode;
    QString cli_tel;

public:
    Client();
    QString getCli_lastname() const;
    void setCli_lastname(const QString &value);
    QString getCli_firstname() const;
    void setCli_firstname(const QString &value);
    QString getCli_address() const;
    void setCli_address(const QString &value);
    QString getCli_city() const;
    void setCli_city(const QString &value);
    QString getCli_postcode() const;
    void setCli_postcode(const QString &value);
    QString getCli_tel() const;
    void setCli_tel(const QString &value);
    int getCli_id() const;
    void setCli_id(int value);
};

#endif // CLIENT_H
