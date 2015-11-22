#include "addcustomeraddlocationaddcontact.h"
#include "ui_addcustomeraddlocationaddcontact.h"

AddCustomerAddLocationAddContact::AddCustomerAddLocationAddContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocationAddContact)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);
}

AddCustomerAddLocationAddContact::~AddCustomerAddLocationAddContact()
{
    delete ui;
}
void AddCustomerAddLocationAddContact::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddLocationAddContact::on_addPhoneButton_clicked()
{
    stringMatrix tmpPhones;
    AddCustomerAddLocationAddContactAddPhone *
            addCustomerAddLocationAddContactAddPhone =
            new AddCustomerAddLocationAddContactAddPhone(this, &tmpPhones, "1");
    addCustomerAddLocationAddContactAddPhone->exec();
}

void AddCustomerAddLocationAddContact::on_addEmailButton_clicked()
{
    stringMatrix tmpEmails;
    AddCustomerAddLocationAddContactAddEmail *
            addCustomerAddLocationAddContactAddEmail =
            new AddCustomerAddLocationAddContactAddEmail(this, &tmpEmails, "2");
    addCustomerAddLocationAddContactAddEmail->exec();
}
