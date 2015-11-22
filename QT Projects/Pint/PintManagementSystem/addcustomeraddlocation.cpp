#include "addcustomeraddlocation.h"
#include "ui_addcustomeraddlocation.h"

AddCustomerAddLocation::AddCustomerAddLocation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocation)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);

    stringVector headers;
    headers.push_back("Name");
    headers.push_back("Surnames");
    contactsModel = new TableModel(nullptr, ui->contactsTableView, contacts, headers, 2);
    ui->contactsTableView->setModel(contactsModel);
    ui->contactsTableView->resizeColumnsToContents();
}

AddCustomerAddLocation::~AddCustomerAddLocation()
{
    delete contactsModel;
    delete ui;
}

void AddCustomerAddLocation::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddLocation::on_addContactButton_clicked()
{
    addContactDialog = new AddCustomerAddLocationAddContact(this, emails, phones, contacts, location);
    connect(addContactDialog, SIGNAL(CloseAndAdd()), this, SLOT(AddContact()));
    addContactDialog->exec();
}

void AddCustomerAddLocation::AddContact() {
    addContactDialog = nullptr;
    contactsModel->ReloadData();
    ui->contactsTableView->resizeColumnsToContents();
}
