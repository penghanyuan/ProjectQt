#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QDialog>
#include "controller/typecontroller.h"
#include "toolbox.h"
namespace Ui {
class AddPerson;
}

class AddPerson : public QDialog
{
    Q_OBJECT

public:
    explicit AddPerson(QWidget *parent = 0);
    ~AddPerson();

private slots:
    void on_person_type_currentIndexChanged(const QString &arg1);

    void on_last_name_txt_editingFinished();

    void on_first_name_txt_editingFinished();

    void on_t_username_editingFinished();

    void on_t_password_editingFinished();

    void on_person_submit_btn_clicked();

private:
    TypeController typeController;
    Ui::AddPerson *ui;
    bool lastname_isempty;
    bool first_isempty;
    bool username_isempty;
    bool password_isempty;
    bool is_techncien;
};

#endif // ADDPERSON_H
