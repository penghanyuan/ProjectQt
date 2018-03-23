#include "adddivers.h"
#include "ui_adddivers.h"
#include "controller/resourcescontroller.h"
#include "controller/typecontroller.h"

addDivers::addDivers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDivers)
{
    ui->setupUi(this);
}

addDivers::~addDivers()
{
    delete ui;
}

void addDivers::on_submit_btn_clicked()
{
    QString lastname = ui->diver_nom_edit->text();
    QString firstname = ui->diver_prenom_edit->text();

//    TypeController tc;
    TypeDAO tdao;
    Type typeDivers = tdao.selectTypeByName("Divers");
    ResourcesController rc;
    rc.addResource(lastname,firstname,typeDivers);
    accept();
}
