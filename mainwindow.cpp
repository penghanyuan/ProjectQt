#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addclient.h"
#include "addperson.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    vector<Resource> v_resources;
    vector<Type> v_types;
    QList<QStandardItem*> ql_type;
    ui->setupUi(this);

    standardModel = new QStandardItemModel(this) ;
    QStandardItem *rootItem = standardModel->invisibleRootItem();
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
                // may have memory leak
                QStandardItem *name = new QStandardItem(v_resources.at(j).getRes_lastname());
                name->setData(QString::number(v_resources.at(j).getRes_id()));
                qsi_type->appendRow(name);
            }
        }
        ql_type.append(qsi_type);
    }
    // bind types on view
    rootItem->appendRows(ql_type);
    standardModel->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("Types")));
    ui->treeView->setModel(standardModel);
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

    add_client.setWindowFlags(add_client.windowFlags()& ~ Qt::WindowMaximizeButtonHint);

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
    if(add_person.exec()==QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have added one person");
    }
}

void MainWindow::on_actionAdd_Person_Icon_triggered()
{
    MainWindow::on_actionAdd_Person_triggered();
}


void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    qDebug()<<standardModel->itemData(index).values()[1].toString();
}
