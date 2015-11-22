#include "addcustomeraddlocationaddcontactaddemail.h"
#include "ui_addcustomeraddlocationaddcontactaddemail.h"

AddCustomerAddLocationAddContactAddEmail::AddCustomerAddLocationAddContactAddEmail(QWidget *parent,
                                                                                   stringMatrix * newEmails,
                                                                                   const std::string & contact) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocationAddContactAddEmail)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);
    this->emails = newEmails;
    this->contact = contact.c_str();
    std::stringstream qryss;
    qryss << "select id, kind from email_phone_kinds";
    Query qry(qryss.str());
    if (qry.failed) {
        emit CloseUponConnectionFailure();
        this->close();
    }
    else {
        for (int i = 0; i < (int)qry.r.size(); ++i){
            std::vector<std::string> newKind;
            newKind.push_back(qry.r[i][0].as<std::string>());
            newKind.push_back(qry.r[i][1].as<std::string>());
            kinds.push_back(newKind);
        }
        QStringList kindOptions;
        for (std::vector<std::vector<std::string>>::iterator tuple = kinds.begin(); tuple != kinds.end(); tuple++){
            kindOptions << (*tuple)[1].c_str();
        }
        ui->kindComboBox->addItems(kindOptions);
    }
}

AddCustomerAddLocationAddContactAddEmail::~AddCustomerAddLocationAddContactAddEmail()
{
    delete ui;
}

void AddCustomerAddLocationAddContactAddEmail::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddLocationAddContactAddEmail::on_addButton_clicked()
{
    std::vector<std::string> newEmail;
    newEmail.push_back(contact);
    newEmail.push_back(ui->addressLineEdit->text().toStdString());
    std::string kindToReport = "";
    for (int i = 0; i < (int)kinds.size(); ++i){
        std::vector<std::string> kind = kinds.at(i);
        if (kind.at(1) == ui->kindComboBox->currentText().toStdString()) {
            kindToReport = kind.at(0);
            break;
        }
    }
    newEmail.push_back(kindToReport);
    std::cout << "New email to add (contact, address, kind): ";
    std::cout << newEmail;
    std::cout << std::endl;
    emails->push_back(newEmail);
    this->close();
}
