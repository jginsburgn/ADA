#include "addcustomeraddlocation.h"
#include "ui_addcustomeraddlocation.h"

AddCustomerAddLocation::AddCustomerAddLocation(QWidget * parent,
                                               stringMatrix * locations,
                                               stringMatrix * contacts,
                                               stringMatrix * phones,
                                               stringMatrix * emails) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocation)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);

    this->locations = locations;
    this->contacts = contacts;
    this->phones = phones;
    this->emails = emails;
    thisLocation = Helper::intToString(locations->size());

    stringVector headers;
    headers.push_back("Name");
    headers.push_back("Surnames");
    contactsModel = new TableModel(nullptr, ui->contactsTableView, displayContacts, headers, 2);
    ui->contactsTableView->setModel(contactsModel);
    ui->contactsTableView->resizeColumnsToContents();
}

AddCustomerAddLocation::~AddCustomerAddLocation()
{
    delete displayContacts;
    delete contactsModel;
    delete ui;
}

void AddCustomerAddLocation::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddLocation::on_addContactButton_clicked()
{
    addContactDialog = new AddCustomerAddLocationAddContact(this,
                                                            emails,
                                                            phones,
                                                            contacts,
                                                            thisLocation);
    connect(addContactDialog, SIGNAL(CloseAndAdd()), this, SLOT(AddContact()));
    addContactDialog->exec();
}

void AddCustomerAddLocation::AddContact() {
    addContactDialog = nullptr;
    displayContacts->push_back(contacts->at(contacts->size() - 1));
    contactsModel->ReloadData();
    ui->contactsTableView->resizeColumnsToContents();
}

void AddCustomerAddLocation::on_addButton_clicked()
{
    stringVector newLocation;
    newLocation.push_back(ui->addressLineEdit->text().toStdString());
    std::cout << "New location to add (address): ";
    std::cout << newLocation;
    std::cout << std::endl;
    locations->push_back(newLocation);
    emit CloseAndAdd();
    this->close();
}
