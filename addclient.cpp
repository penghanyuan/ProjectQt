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
