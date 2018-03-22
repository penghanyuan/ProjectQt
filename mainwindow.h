#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "controller/resourcescontroller.h"
#include "controller/typecontroller.h"
#include "controller/clientcontroller.h"
#include "connectionsql.h"
#include "cool.h"
#include "editclient.h"
#include "controller/planning.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_actionAdd_Client_triggered();

    void on_actionAdd_Client_Icon_triggered();

    void on_actionAdd_Person_triggered();

    void on_actionAdd_Person_Icon_triggered();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_actionCool_triggered();


    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_btn_delete_clicked();

    void on_pushButton_3_clicked();

    void on_planning_search_clicked();

private:
    ResourcesController resourceController;
    TypeController typeController;
    ClientController clientController;
    QStandardItemModel * standardModel;
    AppointmentController appointmentController;
    Ui::MainWindow *ui;


    // variables
    int selected_person_id;
    QList<QStandardItem*> ql_type;
    QSqlTableModel *model;
    QSqlDatabase db;
    QString fil_fname_lname;
    QString fil_date;

    QString fil_date_plan;


    void loadDataForTreeView(QList<QStandardItem*> &ql_type);
    void bindDataOnView();
    void showClientData();
    void searchByLastnameOrFirstname();
    void searchByTime();
};

#endif // MAINWINDOW_H
