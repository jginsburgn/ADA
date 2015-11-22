#include "addcustomeraddlocation.h"
#include "ui_addcustomeraddlocation.h"

AddCustomerAddLocation::AddCustomerAddLocation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocation)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);
}

AddCustomerAddLocation::~AddCustomerAddLocation()
{
    delete ui;
}

void AddCustomerAddLocation::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddLocation::on_addContactButton_clicked()
{
    AddCustomerAddLocationAddContact * addCustomerAddLocationAddContact =
            new AddCustomerAddLocationAddContact(this);
    addCustomerAddLocationAddContact->exec();
}
