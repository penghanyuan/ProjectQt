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
    if(arg1.compare("Informaticien"))
    {
        ui->t_username->setReadOnly(true);
        ui->t_password->setReadOnly(true);
    }
    else
    {
        ui->t_username->setReadOnly(false);
        ui->t_password->setReadOnly(false);
        ui->t_password->clear();
        ui->t_username->clear();
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

}

void AddPerson::on_t_username_editingFinished()
{

}

void AddPerson::on_t_password_editingFinished()
{

}
