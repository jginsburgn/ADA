#include "addcustomeraddlocationaddcontact.h"
#include "ui_addcustomeraddlocationaddcontact.h"

AddCustomerAddLocationAddContact::AddCustomerAddLocationAddContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocationAddContact)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);

    stringVector phonesHeaders;
    phonesHeaders.push_back("Area code");
    phonesHeaders.push_back("Number");
    phonesHeaders.push_back("Extension");
    phonesModel = new TableModel(nullptr, ui->phonesTableView, phones, phonesHeaders, 2);
    ui->phonesTableView->setModel(phonesModel);
    ui->phonesTableView->resizeColumnsToContents();

    stringVector emailsHeaders;
    emailsHeaders.push_back("Address");
    emailsModel = new TableModel(nullptr, ui->emailsTableView, emails, emailsHeaders, 2);
    ui->emailsTableView->setModel(emailsModel);
    ui->emailsTableView->resizeColumnsToContents();
}

AddCustomerAddLocationAddContact::~AddCustomerAddLocationAddContact()
{
    delete phonesModel;
    delete emailsModel;
    delete ui;
}
void AddCustomerAddLocationAddContact::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddLocationAddContact::on_addPhoneButton_clicked()
{
    phoneDialog = new AddCustomerAddLocationAddContactAddPhone(this, phones, contact);
    connect(phoneDialog, SIGNAL(CloseAndAdd()), this, SLOT(PhoneAdded()));
    phoneDialog->exec();
}

void AddCustomerAddLocationAddContact::on_addEmailButton_clicked()
{
    emailDialog = new AddCustomerAddLocationAddContactAddEmail(this, emails, contact);
    connect(emailDialog, SIGNAL(CloseAndAdd()), this, SLOT(EmailAdded()));
    emailDialog->exec();
}

void AddCustomerAddLocationAddContact::PhoneAdded(){
    phonesModel->ReloadData();
    ui->phonesTableView->resizeColumnsToContents();
}

void AddCustomerAddLocationAddContact::EmailAdded(){
    emailsModel->ReloadData();
    ui->emailsTableView->resizeColumnsToContents();
}
