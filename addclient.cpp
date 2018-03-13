#include "addclient.h"
#include "ui_addclient.h"

AddClient::AddClient(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);

}

AddClient::~AddClient()
{
    delete ui;
}

void AddClient::on_client_submit_btn_clicked()
{
    QString lastname;
    QString firstname;
    QString address;
    QString city;
    QString postcode;
    QString tel;
    QString comment;
    QDate rdv_date;
    int rdv_duration;
    int priority;
}
