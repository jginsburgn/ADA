#include "addcustomerwindow.h"
#include "ui_addcustomerwindow.h"

AddCustomerWindow::AddCustomerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddCustomerWindow)
{
    ui->setupUi(this);
    stringVector locationHeaders;
    locationHeaders.push_back("Address");
    locationsModel = new TableModel(nullptr, ui->locationsTableView,
                                    locations, locationHeaders, 0);
    ui->locationsTableView->setModel(locationsModel);
    ui->locationsTableView->resizeColumnsToContents();

    stringVector contactHeaders;
    contactHeaders.push_back("Name");
    contactHeaders.push_back("Surnames");
    contactsModel = new TableModel(nullptr,
                                   ui->contactsTableView,
                                   contacts,
                                   contactHeaders,
                                   2);
    ui->contactsTableView->setModel(contactsModel);
    ui->locationsTableView->resizeColumnsToContents();
}

AddCustomerWindow::~AddCustomerWindow()
{
    delete locations;
    delete contacts;
    delete phones;
    delete emails;
    delete ui;
}

void AddCustomerWindow::on_rfcLineEdit_textChanged(const QString &arg1)
{
    verifyRFCUniqueness(arg1.toStdString());
}

bool AddCustomerWindow::verifyRFCUniqueness(const std::string & rfc){
    std::stringstream qryss;
    qryss << "select id from entity_kinds where kind='Customer'";
    Query qry(qryss.str());
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
    }
    else {
        std::string customerKindId = qry.r[0][qry.r.column_number("id")].as<std::string>();
        qryss.str("");
        qryss << "select id from entities " <<
                 "where rfc=" << pg::quote(rfc) <<
                 " and kind=" << customerKindId;
        qry.setQuery(qryss.str());
        qry.run();
        if (qry.failed) {
            ui->statusbar->showMessage(connectionError.c_str());
        }
        else {
            if (qry.r.size() > 0) ui->statusbar->showMessage(rfcexistscustomer.c_str());
            else {
                ui->statusbar->showMessage(nrfcexistscustomer.c_str());
                return true;
            }
        }
    }
    return false;
}

bool AddCustomerWindow::verifyNameUniqueness(const std::string & rfc){
    std::stringstream qryss;
    qryss << "select id from entity_kinds where kind='Customer'";
    Query qry(qryss.str());
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
    }
    else {
        std::string customerKindId = qry.r[0][qry.r.column_number("id")].as<std::string>();
        qryss.str("");
        qryss << "select id from entities " <<
                 "where entity_name=" << pg::quote(rfc) <<
                 " and kind=" << customerKindId;
        qry.setQuery(qryss.str());
        qry.run();
        if (qry.failed) {
            ui->statusbar->showMessage(connectionError.c_str());
        }
        else {
            if (qry.r.size() > 0) ui->statusbar->showMessage(nameexistscustomer.c_str());
            else {
                ui->statusbar->showMessage(nnameexistscustomer.c_str());
                return true;
            }
        }
    }
    return false;
}

void AddCustomerWindow::on_nameLineEdit_textEdited(const QString &arg1)
{
    verifyNameUniqueness(arg1.toStdString());
}

void AddCustomerWindow::on_addLocationButton_clicked()
{
    locationDialog = new AddCustomerAddLocation(this,
                                       locations,
                                       contacts,
                                       phones,
                                       emails);
    connect(locationDialog, SIGNAL(CloseAndAdd()), this, SLOT(AddLocation()));
    locationDialog->exec();
}

void AddCustomerWindow::AddLocation() {
    locationsModel->ReloadData();
    ui->locationsTableView->resizeColumnsToContents();
}

void AddCustomerWindow::on_addContactButton_clicked()
{
    contactDialog = new AddCustomerAddContact(this,
                                              contacts,
                                              phones,
                                              emails);
    connect(contactDialog, SIGNAL(CloseAndAdd()), this, SLOT(AddContact()));
    contactDialog->exec();
}

void AddCustomerWindow::AddContact() {
    contactsModel->ReloadData();
    ui->contactsTableView->resizeColumnsToContents();
}

void AddCustomerWindow::on_addCustomerButton_clicked()
{
    ui->statusbar->showMessage("Fetching entity kind enum for customers...");
    std::stringstream qryss;
    qryss << "select id from entity_kinds where kind=" << pg::quote("Customer");
    Query qry(qryss.str());
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
        return; 
    }
    std::string customerKindId = qry.r[0][0].as<std::string>();
    qryss.str("");
    
    
    ui->statusbar->showMessage("Inserting entity into database...");
    qryss << "insert into entities (rfc, entity_name, kind) values "
        << "(" <<
           pg::quote(ui->rfcLineEdit->text().toStdString()) << ", " <<
           pg::quote(ui->nameLineEdit->text().toStdString()) << ", " <<
           customerKindId
        << ")";
    qry.setQuery(qryss.str());
    qry.run();
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
        return; 
    }
    qryss.str("");
    
    
    ui->statusbar->showMessage("Finding entity's key...");
    qryss << "select id from entities where rfc="
          << pg::quote(ui->rfcLineEdit->text().toStdString());
    qry.setQuery(qryss.str());
    qry.run();
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
        return; 
    }
    std::string entityId = qry.r[0][0].as<std::string>();
    qryss.str("");


    ui->statusbar->showMessage("Inserting locations...");

    ui->statusbar->showMessage("Inserting locations: finding initial key...");
    qryss << "select id from locations order by id desc limit 1";
    qry.setQuery(qryss.str());
    qry.run();
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
        return;
    }
    int locInitialKey = 1;
    if (qry.r.size() == 1) locInitialKey = qry.r[0][0].as<int>();
    qryss.str("");

    ui->statusbar->showMessage("Inserting locations: "
                               "finding contacts' initial key...");
    qryss << "select id from contacts order by id desc limit 1";
    qry.setQuery(qryss.str());
    qry.run();
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
        return;
    }
    int contactInitialKey = 1;
    if (qry.r.size() == 1) contactInitialKey = qry.r[0][0].as<int>();
    qryss.str("");

    ui->statusbar->showMessage("Inserting locations: "
                               "finding phones' initial key...");
    qryss << "select id from phones order by id desc limit 1";
    qry.setQuery(qryss.str());
    qry.run();
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
        return;
    }
    int phoneInitialKey = 1;
    if (qry.r.size() == 1) phoneInitialKey = qry.r[0][0].as<int>();
    qryss.str("");

    ui->statusbar->showMessage("Inserting locations: "
                               "finding emails' initial key...");
    qryss << "select id from emails order by id desc limit 1";
    qry.setQuery(qryss.str());
    qry.run();
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
        return;
    }
    int emailInitialKey = 1;
    if (qry.r.size() == 1) emailInitialKey = qry.r[0][0].as<int>();
    qryss.str("");

    ui->statusbar->showMessage("Inserting locations: inserting contacts, "
                               "phones and emails...");
    for (int i = 0; i < (int)locations->size(); ++i){
        stringVector currentLocation = locations->at(i);
        qryss << "insert into locations (id, address, entity) values "
              << "(" <<
                 Helper::intToString(++locInitialKey) << ", " <<
                 pg::quote(currentLocation.at(0)) << ", " <<
                 entityId
              << "); ";
        for (int j = 0; j < (int)contacts->size(); ++j) {
            stringVector currentContact = contacts->at(j);
            //Check if current contact relates to current location
            if (currentContact.at(0) == Helper::intToString(i)
                    && currentContact.at(1) == "Through") {
                qryss << "insert into contacts (id, contact_name, surnames) values "
                      << "(" <<
                         Helper::intToString(++contactInitialKey) << ", " <<
                         pg::quote(currentContact.at(2)) << ", " <<
                         pg::quote(currentContact.at(3))
                      << "); ";
                qryss << "insert into locations_contacts(a_location, contact) values "
                      << "(" <<
                         Helper::intToString(locInitialKey) << ", " <<
                         Helper::intToString(contactInitialKey)
                      << "); ";
                //now emails come:
                for (int k = 0; k < (int)emails->size(); ++k) {
                    stringVector currentEmail = emails->at(k);
                    //Check if current email relates to current contact
                    if (currentEmail.at(0) == Helper::intToString(j)) {
                        qryss << "insert into emails(contact, kind, address) values "
                              << "(" <<
                                 Helper::intToString(contactInitialKey) << ", " <<
                                 currentEmail.at(1) << ", " <<
                                 pg::quote(currentEmail.at(2))
                              << "); ";
                    }
                }
                //now phones come:
                for (int k = 0; k < (int)phones->size(); ++k) {
                    stringVector currentPhone = phones->at(k);
                    //Check if current phone relates to current contact
                    if (currentPhone.at(0) == Helper::intToString(j)) {
                        qryss << "insert into phones"
                                 "(contact, kind, area_code, number, phone_extension"
                                 ") values "
                              << "(" <<
                                 Helper::intToString(contactInitialKey) << ", " <<
                                 currentPhone.at(1) << ", " <<
                                 pg::quote(currentPhone.at(2)) << ", " <<
                                 pg::quote(currentPhone.at(3)) << ", " <<
                                 pg::quote(currentPhone.at(4))
                              << "); ";
                    }
                }
            }
        }
    }
    qry.setQuery(qryss.str());
    qry.run();
    if (qry.failed) {
        ui->statusbar->showMessage(connectionError.c_str());
        return;
    }
    ui->statusbar->showMessage("Addition Succeeded");
    ui->addCustomerButton->setEnabled(false);
    sleep(2);
    this->close();
}

void AddCustomerWindow::on_cancelButton_clicked()
{
    this->close();
}
