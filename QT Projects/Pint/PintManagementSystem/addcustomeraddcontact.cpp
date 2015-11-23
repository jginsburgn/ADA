#include "addcustomeraddcontact.h"
#include "ui_addcustomeraddcontact.h"

AddCustomerAddContact::AddCustomerAddContact(QWidget * parent,
                                             stringMatrix * contacts,
                                             stringMatrix * phones,
                                             stringMatrix * emails) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddContact)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);

    this->contacts = contacts;
    this->phones = phones;
    this->emails = emails;
    thisContact = Helper::intToString(contacts->size());

    stringVector phoneHeaders;
    phoneHeaders.push_back("Area Code");
    phoneHeaders.push_back("Number");
    phoneHeaders.push_back("Extension");
    phonesModel = new TableModel(nullptr,
                                 ui->phonesTableView,
                                 displayPhones,
                                 phoneHeaders,
                                 2);
    ui->phonesTableView->setModel(phonesModel);
    ui->phonesTableView->resizeColumnsToContents();

    stringVector emailHeaders;
    emailHeaders.push_back("Address");
    emailsModel = new TableModel(nullptr,
                                 ui->emailsTableView,
                                 displayEmails,
                                 emailHeaders,
                                 2);
    ui->emailsTableView->setModel(emailsModel);
    ui->emailsTableView->resizeColumnsToContents();
}

AddCustomerAddContact::~AddCustomerAddContact()
{
    delete phonesModel;
    delete emailsModel;
    delete displayPhones;
    delete displayEmails;
    delete ui;
}

void AddCustomerAddContact::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddContact::on_addButton_clicked()
{
    stringVector newContact;
    newContact.push_back("null");
    newContact.push_back("Direct");
    newContact.push_back(ui->nameLineEdit->text().toStdString());
    newContact.push_back(ui->surnamesLineEdit->text().toStdString());
    std::cout << "New contact to add (location, through, name, surnames): ";
    std::cout << newContact;
    std::cout << std::endl;
    contacts->push_back(newContact);
    emit CloseAndAdd();
    this->close();
}

void AddCustomerAddContact::AddPhone() {
    displayPhones->push_back(phones->back());
    phonesModel->ReloadData();
    ui->phonesTableView->resizeColumnsToContents();
}

void AddCustomerAddContact::AddEmail() {
    displayEmails->push_back(emails->back());
    emailsModel->ReloadData();
    ui->phonesTableView->resizeColumnsToContents();
}

void AddCustomerAddContact::on_addPhoneButton_clicked()
{
    phoneDialog = new AddCustomerAddContactAddPhone(this,
                                                    phones,
                                                    thisContact);
    connect(phoneDialog, SIGNAL(CloseAndAdd()), this, SLOT(AddPhone()));
    phoneDialog->exec();
}

void AddCustomerAddContact::on_addEmailButton_clicked()
{
    emailDialog = new AddCustomerAddContactAddEmail(this,
                                                    emails,
                                                    thisContact);
    connect(emailDialog, SIGNAL(CloseAndAdd()), this, SLOT(AddEmail()));
    emailDialog->exec();
}
