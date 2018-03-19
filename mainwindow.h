#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "controller/resourcescontroller.h"
#include "controller/typecontroller.h"
#include "cool.h"

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

private:
    ResourcesController resourceController;
    TypeController typeController;
    QStandardItemModel * standardModel;
    Ui::MainWindow *ui;

    void loadDataForTreeView(QList<QStandardItem*> &ql_type);
    void bindDataOnView();
};

#endif // MAINWINDOW_H
