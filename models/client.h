#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
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
    QString cli_comment;
    QDate cli_rdv_date;
    int cli_rdv_duration;
    int cli_priority;


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
    QString getCli_comment() const;
    void setCli_comment(const QString &value);
    QDate getCli_rdv_date() const;
    void setCli_rdv_date(const QDate &value);
    int getCli_rdv_duration() const;
    void setCli_rdv_duration(int value);
    int getCli_priority() const;
    void setCli_priority(int value);

};

#endif // CLIENT_H
