#include "addclient.h"
#include "ui_addclient.h"
#include <QDebug>
#include <QMessageBox>
AddClient::AddClient(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    // set ui
    ui->setupUi(this);
    ui->appointment_date->setDateRange(QDate::currentDate(),QDate::currentDate().addDays(30));
    ui->appointment_duration_txt->setValidator(new QIntValidator);
    ui->postcode_txt->setValidator(new QIntValidator);
    ui->phone_number_txt->setValidator(new QIntValidator);
    this->createMultiCombo();
}

AddClient::~AddClient()
{
    delete ui;
}

/**
 * @brief AddClient::on_client_submit_btn_clicked
 */
void AddClient::on_client_submit_btn_clicked()
{
    on_last_name_txt_editingFinished();
    on_first_name_txt_editingFinished();
    on_city_txt_editingFinished();
    on_appointment_duration_txt_editingFinished();
    on_postcode_txt_editingFinished();
    on_address_txt_editingFinished();
    QString lastname;
    QString firstname;
    QString address;
    QString city;
    QString postcode;
    QString tel;
    QString comment;
    QDate rdv_date;
    QString rdv_duration;
    QString res_string;
    QString remarque;
    int priority;

    if(lastname_isempty||first_isempty||address_isempty||city_isempty||pc_isempty||duration_isempty||res_isempty)
    {
        QMessageBox::warning(this, tr("Waring"),
                                     tr("All field with * can not be empty!!"),
                                     QMessageBox::Ok);
    }
    else
    {
        lastname = ui->last_name_txt->text();
        firstname = ui->first_name_txt->text();
        address = ui->address_txt->text();
        city = ui->city_txt->text();
        postcode = ui->postcode_txt->text();
        rdv_date = ui->appointment_date->date();
        rdv_duration = ui->appointment_duration_txt->text();
        priority = ui->priority->value();
        res_string = pLineEdit->text();
        tel = ui->phone_number_txt->text();
        comment = ui->comment_txt->toPlainText();
        remarque = ui->client_remarque->text();

        comment = comment+"\n"+remarque;
        //add if!!!
        clientController.addClient(lastname,firstname,address,city,postcode,tel,comment,rdv_date,rdv_duration,res_string,priority);
        QMessageBox::information(this, tr("Successful"),
                                     tr("Add client successfully!!"),
                                     QMessageBox::Ok);
        accept();
    }

}


/**
 * @brief AddClient::stateChanged
 * @param state
 */
void AddClient::stateChanged(int state)
{
    bSelected = true;
       QString strSelectedData("");
       strSelectedText.clear();
       int nCount = pListWidget->count();
       for (int i = 0; i < nCount; ++i)
       {
           QListWidgetItem *pItem = pListWidget->item(i);
           QWidget *pWidget = pListWidget->itemWidget(pItem);
           QCheckBox *pCheckBox = (QCheckBox *)pWidget;
           if (pCheckBox->isChecked())
           {
               QString strText = pCheckBox->text();
               strSelectedData.append(strText).append(";");
           }
       }
       if (strSelectedData.endsWith(";"))
           strSelectedData.remove(strSelectedData.count() - 1, 1);
       if (!strSelectedData.isEmpty())
       {
           //ui.comboBox->setEditText(strSelectedData);
           strSelectedText = strSelectedData;
           pLineEdit->setText(strSelectedData);
           pLineEdit->setToolTip(strSelectedData);
       }
       else
       {
           pLineEdit->clear();
           //ui.comboBox->setEditText("");
       }
       bSelected = false;
}

/**
 * @brief AddClient::textChanged
 * @param text
 */
void AddClient::textChanged(const QString &text)
{
    if(pLineEdit->text().isEmpty()){
        pLineEdit->setStyleSheet("background-color: red;");
        res_isempty = true;
    }else{
        pLineEdit->setStyleSheet("background-color: white;");
        res_isempty = false;
    }
    if (!bSelected){
         pLineEdit->setText(strSelectedText);
    }
}

/**
 * @brief AddClient::on_last_name_txt_editingFinished
 */
void AddClient::on_last_name_txt_editingFinished()
{
    if(ui->last_name_txt->text().isEmpty()){
        ui->last_name_txt->setStyleSheet("background-color: red;");
        lastname_isempty = true;
    }else{
        ui->last_name_txt->setStyleSheet("background-color: white;");
        lastname_isempty = false;
    }
    ui->last_name_txt->setText(ToolBox::firstToUpper(ui->last_name_txt->text()));
}


/**
 * @brief AddClient::on_first_name_txt_editingFinished
 */
void AddClient::on_first_name_txt_editingFinished()
{
    if(ui->first_name_txt->text().isEmpty()){
        ui->first_name_txt->setStyleSheet("background-color: red;");
        first_isempty = true;
    }else{
        ui->first_name_txt->setStyleSheet("background-color: white;");
        first_isempty = false;
    }
    ui->first_name_txt->setText(ToolBox::firstToUpper(ui->first_name_txt->text()));

}


/**
 * @brief AddClient::on_city_txt_editingFinished
 */
void AddClient::on_city_txt_editingFinished()
{
    if(ui->city_txt->text().isEmpty()){
        ui->city_txt->setStyleSheet("background-color: red;");
        city_isempty = true;
    }else{
        ui->city_txt->setStyleSheet("background-color: white;");
        city_isempty = false;
    }
    ui->city_txt->setText(ToolBox::firstToUpper(ui->city_txt->text()));
}


/**
 * @brief AddClient::on_address_txt_editingFinished
 */
void AddClient::on_address_txt_editingFinished()
{
    if(ui->address_txt->text().isEmpty()){
        ui->address_txt->setStyleSheet("background-color: red;");
        address_isempty = true;
    }else{
        ui->address_txt->setStyleSheet("background-color: white;");
        address_isempty = false;
    }
}


/**
 * @brief AddClient::on_postcode_txt_editingFinished
 */
void AddClient::on_postcode_txt_editingFinished()
{
    if(ui->postcode_txt->text().isEmpty()){
        ui->postcode_txt->setStyleSheet("background-color: red;");
        pc_isempty = true;
    }else{
        ui->postcode_txt->setStyleSheet("background-color: white;");
        pc_isempty = false;
    }
}


/**
 * @brief AddClient::on_appointment_duration_txt_editingFinished
 */
void AddClient::on_appointment_duration_txt_editingFinished()
{
    if(ui->appointment_duration_txt->text().isEmpty()){
        ui->appointment_duration_txt->setStyleSheet("background-color: red;");
        duration_isempty = true;
    }else{
        ui->appointment_duration_txt->setStyleSheet("background-color: white;");
        duration_isempty = false;
    }
}


/**
 * @brief AddClient::createMultiCombo
 */
void AddClient::createMultiCombo()
{
    // get all aviliable resources and add to list
    vector<Resource> v_res;
    resourceController.getAllResources(v_res);
    pListWidget = new QListWidget(this);
    pLineEdit = new QLineEdit(this);
    for (int i = 0; i < v_res.size(); i++)
      {
            Resource res = v_res.at(i);
            if(res.getRes_id()!=1)
            {
                QListWidgetItem *pItem = new QListWidgetItem(pListWidget);
                pListWidget->addItem(pItem);
                QCheckBox *pCheckBox = new QCheckBox(this);
                pCheckBox->setText(QStringLiteral("%1.%2:%3").arg(res.getRes_id()).arg(res.getRes_lastname()).arg(res.getRes_type().getType_label()));
                pListWidget->addItem(pItem);
                pListWidget->setItemWidget(pItem, pCheckBox);
                connect(pCheckBox, SIGNAL(stateChanged(int)), this, SLOT(stateChanged(int)));
            }
        }
    ui->combo_res_list->setModel(pListWidget->model());
    ui->combo_res_list->setView(pListWidget);
    ui->combo_res_list->setLineEdit(pLineEdit);
    pLineEdit->setReadOnly(true);
    connect(pLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(textChanged(const QString &)));
}
