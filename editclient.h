#ifndef EDITCLIENT_H
#define EDITCLIENT_H

#include <QDialog>
#include <QSqlTableModel>
#include "connectionsql.h"
namespace Ui {
class EditClient;
}

class EditClient : public QDialog
{
    Q_OBJECT

public:
    explicit EditClient(QWidget *parent = 0);
    ~EditClient();
    void loadClient();

    void setClient_id(int value);


private slots:
    void on_submit_clicked();

    void on_pushButton_clicked();

private:
    Ui::EditClient *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
    int client_id;
};

#endif // EDITCLIENT_H
