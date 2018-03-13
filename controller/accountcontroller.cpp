#include "accountcontroller.h"

AccountController::AccountController()
{

}

bool AccountController::verifyLogin(QString username,QString password){
    Account account = accountDAO.selectAccountByUsername(username);
    QString username_db = username;
    QString password_db = account.getAcc_password();
    if(username_db == username&&password_db == password){
        return true;
    }else{
        return false;

    }
}
