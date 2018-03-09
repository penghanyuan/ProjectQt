#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addclient.h"
#include "addperson.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Your are connected to the system!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_Client_triggered()
{
    AddClient add_client;

    //add_client.setWindowFlags(add_client.windowFlags()& ~ Qt::WindowMaximizeButtonHint);
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
