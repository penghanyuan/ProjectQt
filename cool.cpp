#include "cool.h"
#include "ui_cool.h"

Cool::Cool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cool)
{
    ui->setupUi(this);
}

Cool::~Cool()
{
    delete ui;
}
