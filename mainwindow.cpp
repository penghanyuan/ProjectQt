#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addclient.h"
#include "addperson.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->bindDataOnView();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->statusBar->showMessage("You are connected to the system!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_Client_triggered()
{
    AddClient add_client;

    if(add_client.exec()==QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have added one client");
    }
}

void MainWindow::on_actionAdd_Client_Icon_triggered()
{
    MainWindow::on_actionAdd_Client_triggered();
}

void MainWindow::on_actionAdd_Person_triggered()
{
    AddPerson add_person;
    add_person.setIs_Edit(false);
    if(add_person.exec()==QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have added one person");
        this->bindDataOnView();
    }
}

void MainWindow::on_actionAdd_Person_Icon_triggered()
{
    MainWindow::on_actionAdd_Person_triggered();
}

/**
 * @brief edit a person
 * @param index
 */
void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
//    EditResource editResource;
//    editResource.showResource(standardModel->itemData(index).values()[1].toInt());
    AddPerson add_person;
    add_person.setIs_Edit(true);
    add_person.showResource(standardModel->itemData(index).values()[1].toInt());
    if(add_person.exec()==QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have edited one person");
        this->bindDataOnView();
    }
   // qDebug()<<"id "+standardModel->itemData(index).values()[1].toString();
}

void MainWindow::on_actionCool_triggered()
{
    Cool cool;
    cool.exec();
}

void MainWindow::loadDataForTreeView(QList<QStandardItem*> &ql_type)
{
    vector<Resource> v_resources;
    vector<Type> v_types;
    // get info from DB
    resourceController.getAllResources(v_resources);
    typeController.getAllType(v_types);
    // create type items
    for(unsigned long i = 0;i<v_types.size();i++)
    {
        QString type_label = v_types.at(i).getType_label();
        QStandardItem * qsi_type = new QStandardItem(type_label);
        // create resources items
        for(unsigned long j = 0;j<v_resources.size();j++)
        {
            QString res_type_label = v_resources.at(j).getRes_type().getType_label();
            if(res_type_label.compare(type_label)==0)
            {
                // may have memory leak!!!!
                QStandardItem *name = new QStandardItem(v_resources.at(j).getRes_lastname());
                name->setData(QString::number(v_resources.at(j).getRes_id()));
                qsi_type->appendRow(name);
            }
        }
        ql_type.append(qsi_type);
    }
}

void MainWindow::bindDataOnView()
{
    QList<QStandardItem*> ql_type;
    // new
    standardModel = new QStandardItemModel(this) ;
    QStandardItem *rootItem = standardModel->invisibleRootItem();

    // load data from db
    this->loadDataForTreeView(ql_type);

    // bind types on view
    rootItem->appendRows(ql_type);
    standardModel->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("Types")));
    ui->treeView->setModel(standardModel);
}
