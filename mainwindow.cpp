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
    this->showClientData();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->planning_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->statusBar->showMessage("You are connected to the system!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// "and client", "add resource" button trigger are as follows:
void MainWindow::on_actionAdd_Client_triggered()
{
    AddClient add_client;

    if(add_client.exec()==QDialog::Accepted)
    {
        model->select();
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


void MainWindow::on_actionCool_triggered()
{
    Cool cool;
    cool.exec();
}


/**
 * edie a person
 * @brief on_treeView_doubleClicked
 * @param index
 */
void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
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



/**
 * @brief MainWindow::loadDataForTreeView
 * @param qlist_type
 */
void MainWindow::loadDataForTreeView(QList<QStandardItem*> &qlist_type)
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
        qsi_type->setData(-1);
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
        qlist_type.append(qsi_type);
    }
}

/**
 * @brief MainWindow::bindDataOnView
 */
void MainWindow::bindDataOnView()
{
    // new
    standardModel = new QStandardItemModel(this) ;

    QStandardItem *rootItem = standardModel->invisibleRootItem();

    for(int i = 0;i<ql_type.size();i++)
    {
        if(ql_type[i]!=NULL)
        {
            qDebug()<<"delete";
            ql_type[i]->removeRows(0,ql_type[i]->rowCount());
            delete ql_type[i];
            ql_type[i] = NULL;
        }
    }
    ql_type.clear();
    // load data from db
    this->loadDataForTreeView(ql_type);

    // bind types on view
    rootItem->appendRows(ql_type);
    standardModel->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("Types")));
    ui->treeView->setModel(standardModel);
}

/**
 * @brief MainWindow::showClientData
 */
void MainWindow::showClientData()
{
    ConnectionSQL *connection = ConnectionSQL::getConnection();
    db = connection->getDb();

    // use a QSqlTableModel
    model = new QSqlTableModel(this,db);
    model->setTable("TClient");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->removeColumn(3);
    model->removeColumn(3);
    model->removeColumn(3);
    model->removeColumn(3);
    model->removeColumn(3);
    model->removeColumn(4);
    model->removeColumn(4);

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

/**
 * @brief MainWindow::searchByLastnameOrFirstname
 */
void MainWindow::searchByLastnameOrFirstnameOrId()
{
    QString s_lastname;
    QString s_firstname;
    QString s_id;
    s_lastname = ui->s_lastname_txt->text();
    s_firstname = ui->s_firstname_txt->text();
    s_id = ui->s_id->text();
    if(!s_lastname.isEmpty())
    {
        s_lastname = s_lastname+"%";
    }
    if(!s_firstname.isEmpty())
    {
        s_firstname = s_firstname+"%";
    }
    if(s_lastname.isEmpty()&&s_firstname.isEmpty())
    {
        s_lastname = '%';
    }
    if(s_id.isEmpty())
    {
        fil_fname_lname = "Nom LIKE '"+s_lastname+"' or Prenom like '"+s_firstname+"'";
    }
    else
    {
        fil_fname_lname = "Id = "+s_id+" and (Nom LIKE '"+s_lastname+"' or Prenom like '"+s_firstname+"')";
    }



}

/**
 * @brief MainWindow::searchByTime
 */
void MainWindow::searchByTime()
{
    QDate s_fdate = ui->fdate->date();
    QDate s_edate = ui->edate->date();

    fil_date = QObject::tr("DateRdv BETWEEN '%1' AND '%2'").arg(s_fdate.toString("yyyy-MM-dd")).arg(s_edate.toString("yyyy-MM-dd"));
}




/**
 * The double clicks actions in the tableview: to edit the informations of a client
 * @brief MainWindow::on_tableView_doubleClicked
 * @param index
 */
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    EditClient editClient;

    // get client id
    int client_id = model->index(index.row(),0).data().toInt();
    editClient.setClient_id(client_id);
    editClient.loadClient();
    if(editClient.exec()==QDialog::Accepted)
    {
        model->select();
//        ui->tableView->setModel(model);
        ui->statusBar->showMessage("You have edited one client");
    }

}

/**
 * @brief search function
 */
void MainWindow::on_pushButton_clicked()
{
    searchByLastnameOrFirstnameOrId();
    if(ui->enable_date->isChecked())
    {
        searchByTime();
        qDebug()<<QObject::tr("(%1) AND (%2)").arg(fil_fname_lname).arg(fil_date);
        model->setFilter(QObject::tr("(%1) AND (%2)").arg(fil_fname_lname).arg(fil_date));

    }
    else
    {
        model->setFilter(QObject::tr("%1").arg(fil_fname_lname));
    }
    model->select();

}

/**
 * @brief MainWindow::on_treeView_clicked
 * @param index
 */
void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    int id = standardModel->itemData(index).values()[1].toInt();
    if(id>0)
    {
        selected_person_id = id;
    }

}

/**
 * delete a resource
 * @brief MainWindow::on_btn_delete_clicked
 */
void MainWindow::on_btn_delete_clicked()
{
    if(resourceController.deleteResource(selected_person_id))
    {
        ui->statusBar->showMessage("You have deleted one person");
        this->bindDataOnView();
    }
}

/**
 * @brief save planning
 */
void MainWindow::on_pushButton_3_clicked()
{
   vector<Client> v_clients;
   QDate s_dateRdv = ui->searchDate->date();
   Planning planning;
   planning.excuteAlgoPlanning(s_dateRdv);

   QString fileName;
   fileName = QFileDialog::getSaveFileName(this,
       QObject::tr("Save planning"), "/home/Desktop/Planning.txt", QObject::tr("Text Files (*.txt)"));

   if (!fileName.isNull())
   {
       planning.saveFile(fileName);
   }else{

   }

}

void MainWindow::on_planning_search_clicked()
{
    QDate s_dateRdv = ui->searchDate->date();
    QSqlTableModel *planning_model = new QSqlTableModel(this,db);
    qDebug()<<s_dateRdv.toString("yyyy-MM-dd");
    planning_model->setTable("TClient");
    fil_date = QObject::tr("DateRdv = '%1'").arg(s_dateRdv.toString("yyyy-MM-dd"));
    planning_model->setFilter(fil_date);
    planning_model->select();
    ui->planning_table->setModel(planning_model);
}

void MainWindow::on_s_id_textChanged(const QString &arg1)
{
    QString pattern("^[0-9]*$");
    QRegExp rx(pattern);
    bool match = rx.exactMatch(arg1);
    if(!match)
    {
        ui->s_id->clear();
    }
}
