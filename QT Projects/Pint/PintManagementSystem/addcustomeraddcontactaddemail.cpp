#include "addcustomeraddcontactaddemail.h"
#include "ui_addcustomeraddcontactaddemail.h"

AddCustomerAddContactAddEmail::AddCustomerAddContactAddEmail(QWidget * parent,
                                                             stringMatrix * emails,
                                                             std::string contact) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddContactAddEmail)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);

    this->emails = emails;
    this->contact = contact;

    std::stringstream qryss;
    qryss << "select id, kind " <<
             "from email_phone_kinds";
    Query qry(qryss.str());
    if (qry.failed) {
        emit CloseUponConnectionFailure();
        this->close();
    }
    else {
        QStringList comboBoxTexts;
        for (int i = 0; i < (int)qry.r.size(); ++i) {
            stringVector newKind;
            newKind.push_back(qry.r[i][0].as<std::string>());
            newKind.push_back(qry.r[i][1].as<std::string>());
            kinds.push_back(newKind);
            comboBoxTexts << qry.r[i][1].as<std::string>().c_str();
        }
        ui->kindComboBox->addItems(comboBoxTexts);
    }
}

AddCustomerAddContactAddEmail::~AddCustomerAddContactAddEmail()
{
    delete ui;
}

void AddCustomerAddContactAddEmail::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddContactAddEmail::on_addButton_clicked()
{
    stringVector newEmail;
    newEmail.push_back(contact);
    std::string kindToAdd = "";
    for (int i = 0; i < (int)kinds.size(); ++i) {
        if (kinds.at(i).at(1) == ui->kindComboBox->currentText().toStdString()) {
            kindToAdd = kinds.at(i).at(0);
            break;
        }
    }
    newEmail.push_back(kindToAdd);
    newEmail.push_back(ui->addressLineEdit->text().toStdString());
    std::cout << "New email to add (contact, kind, address): ";
    std::cout << newEmail;
    std::cout << std::endl;
    emails->push_back(newEmail);
    emit CloseAndAdd();
    this->close();
}
