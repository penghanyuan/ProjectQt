#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>

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
    void on_client_submit_btn_clicked();

private:
    Ui::AddClient *ui;
};

#endif // ADDCLIENT_H
