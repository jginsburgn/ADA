#include "addcustomeraddlocationaddcontactaddemail.h"
#include "ui_addcustomeraddlocationaddcontactaddemail.h"

AddCustomerAddLocationAddContactAddEmail::AddCustomerAddLocationAddContactAddEmail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocationAddContactAddEmail)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);
}

AddCustomerAddLocationAddContactAddEmail::~AddCustomerAddLocationAddContactAddEmail()
{
    delete ui;
}

void AddCustomerAddLocationAddContactAddEmail::on_cancelButton_clicked()
{
    this->close();
}
