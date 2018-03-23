#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QLineEdit>
#include "controller/resourcescontroller.h"
#include "controller/clientcontroller.h"
#include "toolbox.h"
namespace Ui {
class AddClient;
}

class AddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AddClient(QDialog *parent = 0);
    ~AddClient();

private slots:

    //listen to the action of commit button
    void on_client_submit_btn_clicked();

    //listen to the state changes of listbox
    void stateChanged(int state);
    void textChanged(const QString &text);

    //checkout if user has fill all of the required blanks
    void on_last_name_txt_editingFinished();
    void on_first_name_txt_editingFinished();
    void on_city_txt_editingFinished();
    void on_address_txt_editingFinished();
    void on_postcode_txt_editingFinished();
    void on_appointment_duration_txt_editingFinished();

private:
    // ui
    Ui::AddClient *ui;
    QListWidget* pListWidget;
    QLineEdit* pLineEdit;

    // controllers
    ResourcesController resourceController;
    ClientController clientController;

    // variables
    bool bSelected;
    QString strSelectedText;
    bool lastname_isempty;
    bool first_isempty;
    bool address_isempty;
    bool city_isempty;
    bool pc_isempty;
    bool res_isempty;
    bool duration_isempty;

    // functions
    void createMultiCombo();


};

#endif // ADDCLIENT_H
