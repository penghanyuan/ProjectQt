#include "client.h"

QString Client::getCli_lastname() const
{
    return cli_lastname;
}

void Client::setCli_lastname(const QString &value)
{
    cli_lastname = value;
}

QString Client::getCli_firstname() const
{
    return cli_firstname;
}

void Client::setCli_firstname(const QString &value)
{
    cli_firstname = value;
}

QString Client::getCli_address() const
{
    return cli_address;
}

void Client::setCli_address(const QString &value)
{
    cli_address = value;
}

QString Client::getCli_city() const
{
    return cli_city;
}

void Client::setCli_city(const QString &value)
{
    cli_city = value;
}

int Client::getCli_id() const
{
    return cli_id;
}

void Client::setCli_id(int value)
{
    cli_id = value;
}

QString Client::getCli_comment() const
{
    return cli_comment;
}

void Client::setCli_comment(const QString &value)
{
    cli_comment = value;
}

QDate Client::getCli_rdv_date() const
{
    return cli_rdv_date;
}

void Client::setCli_rdv_date(const QDate &value)
{
    cli_rdv_date = value;
}

int Client::getCli_rdv_duration() const
{
    return cli_rdv_duration;
}

void Client::setCli_rdv_duration(int value)
{
    cli_rdv_duration = value;
}

int Client::getCli_priority() const
{
    return cli_priority;
}

void Client::setCli_priority(int value)
{
    cli_priority = value;
}

vector<int>& Client::getCli_v_resources()
{
    return cli_v_resources;
}

void Client::setCli_v_resources(const vector<int> value)
{
    cli_v_resources = value;
}

int Client::getCli_postcode() const
{
    return cli_postcode;
}

void Client::setCli_postcode(int value)
{
    cli_postcode = value;
}

int Client::getCli_tel() const
{
    return cli_tel;
}

void Client::setCli_tel(int value)
{
    cli_tel = value;
}

QString Client::getRemarque() const
{
    return remarque;
}

void Client::setRemarque(const QString &value)
{
    remarque = value;
}

Client::Client()
{
    
}
