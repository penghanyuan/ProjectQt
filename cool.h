#ifndef COOL_H
#define COOL_H

#include <QDialog>

namespace Ui {
class Cool;
}

class Cool : public QDialog
{
    Q_OBJECT

public:
    explicit Cool(QWidget *parent = 0);
    ~Cool();

private:
    Ui::Cool *ui;
};

#endif // COOL_H
