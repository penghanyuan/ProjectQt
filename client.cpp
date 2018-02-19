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

QString Client::getCli_postcode() const
{
    return cli_postcode;
}

void Client::setCli_postcode(const QString &value)
{
    cli_postcode = value;
}

QString Client::getCli_tel() const
{
    return cli_tel;
}

void Client::setCli_tel(const QString &value)
{
    cli_tel = value;
}

int Client::getCli_id() const
{
    return cli_id;
}

void Client::setCli_id(int value)
{
    cli_id = value;
}

Client::Client()
{

}
