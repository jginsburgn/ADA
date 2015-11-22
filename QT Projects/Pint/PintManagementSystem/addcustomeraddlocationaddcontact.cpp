#include "addcustomeraddlocationaddcontact.h"
#include "ui_addcustomeraddlocationaddcontact.h"

AddCustomerAddLocationAddContact::AddCustomerAddLocationAddContact(QWidget *parent,
                                                                   stringMatrix * emails,
                                                                   stringMatrix * phones,
                                                                   stringMatrix * contacts,
                                                                   std::string location) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocationAddContact)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);

    this->emails = emails;
    this->phones = phones;
    this->contacts = contacts;
    this->location = location;

    stringVector phonesHeaders;
    phonesHeaders.push_back("Area code");
    phonesHeaders.push_back("Number");
    phonesHeaders.push_back("Extension");
    phonesModel = new TableModel(nullptr, ui->phonesTableView, displayPhones, phonesHeaders, 2);
    ui->phonesTableView->setModel(phonesModel);
    ui->phonesTableView->resizeColumnsToContents();

    stringVector emailsHeaders;
    emailsHeaders.push_back("Address");
    emailsModel = new TableModel(nullptr, ui->emailsTableView, displayEmails, emailsHeaders, 2);
    ui->emailsTableView->setModel(emailsModel);
    ui->emailsTableView->resizeColumnsToContents();
}

AddCustomerAddLocationAddContact::~AddCustomerAddLocationAddContact()
{
    delete displayPhones;
    delete displayEmails;
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
    phoneDialog = new AddCustomerAddLocationAddContactAddPhone(this, phones,
                                                               Helper::intToString(contacts->size()));
    connect(phoneDialog, SIGNAL(CloseAndAdd()), this, SLOT(PhoneAdded()));
    phoneDialog->exec();
}

void AddCustomerAddLocationAddContact::on_addEmailButton_clicked()
{
    emailDialog = new AddCustomerAddLocationAddContactAddEmail(this, emails,
                                                               Helper::intToString(contacts->size()));
    connect(emailDialog, SIGNAL(CloseAndAdd()), this, SLOT(EmailAdded()));
    emailDialog->exec();
}

void AddCustomerAddLocationAddContact::PhoneAdded(){
    phoneDialog = nullptr;
    displayPhones->push_back(phones->at(phones->size() - 1));
    phonesModel->ReloadData();
    ui->phonesTableView->resizeColumnsToContents();
}

void AddCustomerAddLocationAddContact::EmailAdded(){
    emailDialog = nullptr;
    displayEmails->push_back(emails->at(emails->size() - 1));
    emailsModel->ReloadData();
    ui->emailsTableView->resizeColumnsToContents();
}

void AddCustomerAddLocationAddContact::on_addButton_clicked()
{
    stringVector newContact;
    newContact.push_back(location);
    newContact.push_back("Through");
    newContact.push_back(ui->nameLineEdit->text().toStdString());
    newContact.push_back(ui->surnamesLineEdit->text().toStdString());
    std::cout << "New contact to add (location, through, name, surnames): ";
    std::cout << newContact;
    std::cout << std::endl;
    contacts->push_back(newContact);
    emit CloseAndAdd();
    this->close();
}
