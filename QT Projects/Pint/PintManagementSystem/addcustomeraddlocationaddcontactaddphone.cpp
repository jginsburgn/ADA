#include "addcustomeraddlocationaddcontactaddphone.h"
#include "ui_addcustomeraddlocationaddcontactaddphone.h"

AddCustomerAddLocationAddContactAddPhone::AddCustomerAddLocationAddContactAddPhone(QWidget * parent,
                                                                                   stringMatrix * phones,
                                                                                   const std::string & contact) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddLocationAddContactAddPhone)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);
    this->phones = phones;
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

AddCustomerAddLocationAddContactAddPhone::~AddCustomerAddLocationAddContactAddPhone()
{
    delete ui;
}

void AddCustomerAddLocationAddContactAddPhone::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddLocationAddContactAddPhone::on_addButton_clicked()
{
    std::vector<std::string> newPhone;
    newPhone.push_back(contact);
    std::string kindToReport = "";
    for (int i = 0; i < (int)kinds.size(); ++i){
        std::vector<std::string> kind = kinds.at(i);
        if (kind.at(1) == ui->kindComboBox->currentText().toStdString()) {
            kindToReport = kind.at(0);
            break;
        }
    }
    newPhone.push_back(kindToReport);
    newPhone.push_back(ui->areaCodeLineEdit->text().toStdString());
    newPhone.push_back(ui->numberLineEdit->text().toStdString());
    newPhone.push_back(ui->extensionLineEdit->text().toStdString());
    std::cout << "New phone to add (contact, kind, area code, number, ext): ";
    std::cout << newPhone;
    std::cout << std::endl;
    phones->push_back(newPhone);
    emit CloseAndAdd();
    this->close();
}

void AddCustomerAddLocationAddContactAddPhone::on_pushButton_clicked()
{
    emit CloseAndAdd();
}
