#include "addperson.h"
#include "ui_addperson.h"
AddPerson::AddPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPerson)
{
    ui->setupUi(this);
    this->createTypesCombo();
}

AddPerson::~AddPerson()
{
    delete ui;
}


/**
 * @brief AddPerson::setIs_Edit
 * @param is
 */
void AddPerson::setIs_Edit(bool is)
{
    this->is_edit = is;
}



/**
 * @brief show resource in window
 * @param id
 */
void AddPerson::showResource(int id)
{
    this->res_id = id;
    Resource resource = loadResourceFromDB();
    ui->first_name_txt->setText(resource.getRes_firstname());
    ui->last_name_txt->setText(resource.getRes_lastname());
    ui->person_type->setCurrentIndex(resource.getRes_type().getType_id()-1);
    if(resource.getRes_type().getType_label().compare("Informaticien")==0)
    {
        ui->t_username->setReadOnly(false);
        ui->t_password->setReadOnly(false);
        Account account = accountController.getAccountByResourceId(this->res_id);
        ui->t_username->setText(account.getAcc_username());
        ui->t_password->setText(account.getAcc_password());
    }
}


/**
 * @brief AddPerson::on_person_type_currentIndexChanged
 * @param arg1
 */
void AddPerson::on_person_type_currentIndexChanged(const QString &arg1)
{
    if(arg1.compare("7.Informaticien")==0)
    {
        ui->t_username->setReadOnly(false);
        ui->t_password->setReadOnly(false);
        is_techncien = true;
    }
    else
    {
        ui->t_username->setReadOnly(true);
        ui->t_password->setReadOnly(true);
        ui->t_password->clear();
        ui->t_username->clear();
        ui->t_password->setStyleSheet("background-color: white;");
        password_isempty = false;
        ui->t_username->setStyleSheet("background-color: white;");
        username_isempty = false;
        is_techncien = false;

    }
}

void AddPerson::on_last_name_txt_editingFinished()
{
    if(ui->last_name_txt->text().isEmpty()){
        ui->last_name_txt->setStyleSheet("background-color: red;");
        lastname_isempty = true;
    }else{
        ui->last_name_txt->setStyleSheet("background-color: white;");
        lastname_isempty = false;
    }
    ui->last_name_txt->setText(ToolBox::firstToUpper(ui->last_name_txt->text()));
}

void AddPerson::on_first_name_txt_editingFinished()
{
    if(ui->first_name_txt->text().isEmpty()){
        ui->first_name_txt->setStyleSheet("background-color: red;");
        first_isempty = true;
    }else{
        ui->first_name_txt->setStyleSheet("background-color: white;");
        first_isempty = false;
    }
    ui->first_name_txt->setText(ToolBox::firstToUpper(ui->first_name_txt->text()));
}

void AddPerson::on_t_username_editingFinished()
{
    if(is_techncien&&ui->t_username->text().isEmpty()){
        ui->t_username->setStyleSheet("background-color: red;");
        username_isempty = true;
    }else if(is_techncien){
        ui->t_username->setStyleSheet("background-color: white;");
        username_isempty = false;
    }
}

void AddPerson::on_t_password_editingFinished()
{
    if(is_techncien&&ui->t_password->text().isEmpty()){
        ui->t_password->setStyleSheet("background-color: red;");
        password_isempty = true;
    }else if(is_techncien){
        ui->t_password->setStyleSheet("background-color: white;");
        password_isempty = false;
    }
    ui->t_password->setText(ToolBox::firstToUpper(ui->t_password->text()));
}

void AddPerson::on_person_submit_btn_clicked()
{
    on_t_password_editingFinished();
    on_t_username_editingFinished();
    on_first_name_txt_editingFinished();
    on_last_name_txt_editingFinished();
    QString lastname;
    QString firstname;
    QString type;
    QString username;
    QString password;
    if(first_isempty||lastname_isempty||(is_techncien&&(username_isempty||password_isempty)))
    {
        QMessageBox::warning(this, tr("Waring"),
                                     tr("All field with * can not be empty!!"),
                                     QMessageBox::Ok);
    }
    else
    {
        bool success = false;
        lastname = ui->last_name_txt->text();
        firstname = ui->first_name_txt->text();
        type = ui->person_type->currentText();
        if(is_techncien)// is technicien
        {
            username = ui->t_username->text();
            password = ui->t_password->text();
            if(is_edit)//edit a person
            {
                success = resourceController.modifyTechnicien(this->res_id,lastname,firstname,type,username,password);
            }else
            {
                success = resourceController.addTechnicien(lastname,firstname,type,username,password);
            }

        }
        else
        {
            if(is_edit)//edit
            {
                success = resourceController.modifyResource(this->res_id,lastname,firstname,type);
            }
            else
            {
                success = resourceController.addResource(lastname,firstname,type);
            }
        }
        if(success)
        {
            if(is_edit)
            {
                QMessageBox::information(this, tr("Successful"),
                                             tr("Edit person successfully!!"),
                                             QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this, tr("Successful"),
                                             tr("Add person successfully!!"),
                                             QMessageBox::Ok);
            }
            accept();
        }
    }
}

/**
 * @brief load on person from db
 * @return
 */
Resource AddPerson::loadResourceFromDB()
{
    return resourceController.getResourceById(this->res_id);
}

void AddPerson::createTypesCombo()
{
    vector<Type> v_type;
    QStringList qs_list;
    typeController.getAllType(v_type);
    for(unsigned long i = 0;i<v_type.size();i++)
    {
        qs_list.append(QStringLiteral("%1.%2").arg(v_type.at(i).getType_id()).arg(v_type.at(i).getType_label()));
    }

    ui->person_type->addItems(qs_list);
}
