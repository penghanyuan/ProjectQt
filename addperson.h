#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QDialog>
#include <QStringLiteral>
#include <QMessageBox>
#include "controller/typecontroller.h"
#include "controller/accountcontroller.h"
#include "controller/resourcescontroller.h"
#include "toolbox.h"
#include "models/account.h"

namespace Ui {
class AddPerson;
}

class AddPerson : public QDialog
{
    Q_OBJECT

public:
    explicit AddPerson(QWidget *parent = 0);
    ~AddPerson();
    void setIs_Edit(bool);
    void showResource(int id);
private slots:
    void on_person_type_currentIndexChanged(const QString &arg1);

    void on_last_name_txt_editingFinished();

    void on_first_name_txt_editingFinished();

    void on_t_username_editingFinished();

    void on_t_password_editingFinished();

    void on_person_submit_btn_clicked();

private:
    TypeController typeController;
    AccountController accountController;
    ResourcesController resourceController;
    Ui::AddPerson *ui;
    bool lastname_isempty;
    bool first_isempty;
    bool username_isempty;
    bool password_isempty;
    bool is_techncien;
    bool is_edit;
    int res_id;

    // functions
    Resource loadResourceFromDB();
    void createTypesCombo();
};

#endif // ADDPERSON_H
