#include "addcustomerwindow.h"
#include "ui_addcustomerwindow.h"

AddCustomerWindow::AddCustomerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddCustomerWindow)
{
    ui->setupUi(this);
}

AddCustomerWindow::~AddCustomerWindow()
{
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
