#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addclient.h"
#include "addperson.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    vector<Resource> v_resources;
    vector<Type> v_types;
    QList<QStandardItem*> ql_type;
    ui->setupUi(this);
    QStandardItemModel * standardModel = new QStandardItemModel(this) ;
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
                qsi_type->appendRow(new QStandardItem(v_resources.at(j).getRes_lastname()));
            }
        }
        ql_type.append(qsi_type);
    }
    // bind types on view
    rootItem->appendRows(ql_type);
    standardModel->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("Types")));
    ui->treeView->setModel(standardModel);
    ui->statusBar->showMessage("Your are connected to the system!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_Client_triggered()
{
    AddClient add_client;

    add_client.setWindowFlags(add_client.windowFlags()& ~ Qt::WindowMaximizeButtonHint);
    add_client.exec();
}

void MainWindow::on_actionAdd_Client_Icon_triggered()
{
    MainWindow::on_actionAdd_Client_triggered();
}

void MainWindow::on_actionAdd_Person_triggered()
{
    AddPerson add_person;
    add_person.exec();
}

void MainWindow::on_actionAdd_Person_Icon_triggered()
{
    MainWindow::on_actionAdd_Person_triggered();
}
