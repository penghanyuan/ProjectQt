#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "controller/accountcontroller.h"
#include "QMessageBox"
#include <iostream>
using namespace std;
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_connect_clicked();
    void savecfg();
    void loadcfg();



    void on_username_textEdited(const QString &arg1);

    void on_password_textEdited(const QString &arg1);

private:
    Ui::Login *ui;
    QString  login_username;
    QString  login_password;
};

#endif // LOGIN_H
