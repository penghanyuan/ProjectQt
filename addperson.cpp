#include "addperson.h"
#include "ui_addperson.h"
AddPerson::AddPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPerson)
{

    vector<Type> v_type;
    QStringList qs_list;
    typeController.getAllType(v_type);
    for(unsigned long i = 0;i<v_type.size();i++)
    {
        qs_list.append(v_type.at(i).getType_label());
    }
    ui->setupUi(this);
    ui->person_type->addItems(qs_list);

}

AddPerson::~AddPerson()
{
    delete ui;
}

void AddPerson::on_person_type_currentIndexChanged(const QString &arg1)
{
    if(arg1.compare("Informaticien")==0)
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
    ui->t_username->setText(ToolBox::firstToUpper(ui->t_username->text()));
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
}
