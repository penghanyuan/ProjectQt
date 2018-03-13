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
    ui->comboBox_per->addItems(qs_list);

}

AddPerson::~AddPerson()
{
    delete ui;
}

void AddPerson::on_comboBox_per_currentIndexChanged(const QString &arg1)
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
    }
}
