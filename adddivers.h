#ifndef ADDDIVERS_H
#define ADDDIVERS_H

#include <QDialog>

namespace Ui {
class addDivers;
}

class addDivers : public QDialog
{
    Q_OBJECT

public:
    explicit addDivers(QWidget *parent = 0);
    ~addDivers();

private slots:
    void on_submit_btn_clicked();

private:
    Ui::addDivers *ui;
};

#endif // ADDDIVERS_H
