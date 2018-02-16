#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_connect_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    LoginController logController;
    if(logController.verifyLogin(username,password)){
        accept();
    }else{
        QMessageBox::warning(this, tr("Waring"),
                                     tr("user name or password error!"),
                                     QMessageBox::Ok);
        ui->password->clear();
    }
}
