#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QDialog>
#include "controller/typecontroller.h"
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
    void on_comboBox_per_currentIndexChanged(const QString &arg1);

private:
    TypeController typeController;
    Ui::AddPerson *ui;
};

#endif // ADDPERSON_H
