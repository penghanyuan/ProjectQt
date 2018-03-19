#include "accountcontroller.h"

AccountController::AccountController()
{

}

bool AccountController::verifyLogin(QString username,QString password){
    Account account = accountDAO.selectAccountByUsername(username);
    QString username_db = username;
    QString password_db = account.getAcc_password();
    qDebug()<<username+" "+username_db+","+password+" "+password_db;
    if(username_db.compare(username)==0&&password_db.compare(password)==0){
        return true;
    }else{
        return false;

    }
}

bool AccountController::addAccount(QString username, QString password, Resource resource)
{
    Account account;
    account.setAcc_username(username);
    account.setAcc_password(password);
    account.setAcc_resource(resource);
    accountDAO.insertAccount(account);
}

Account AccountController::getAccountByResourceId(int res_id)
{
    return accountDAO.selectAccountByResourceId(res_id);
}
