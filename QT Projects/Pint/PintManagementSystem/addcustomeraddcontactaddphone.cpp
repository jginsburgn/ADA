#include "addcustomeraddcontactaddphone.h"
#include "ui_addcustomeraddcontactaddphone.h"

AddCustomerAddContactAddPhone::AddCustomerAddContactAddPhone(QWidget * parent,
                                                             stringMatrix * phones,
                                                             std::string contact) :
    QDialog(parent),
    ui(new Ui::AddCustomerAddContactAddPhone)
{
    ui->setupUi(this);
    ui->addButton->setDefault(true);

    this->phones = phones;
    this->contact = contact;

    std::stringstream qryss;
    qryss << "select id, kind from " <<
             "email_phone_kinds";
    Query qry(qryss.str());
    if (qry.failed){
        emit CloseUponConnectionFailure();
    }
    else {
        QStringList comboBoxKinds;
        for (int i = 0; i < (int)qry.r.size(); ++i){
            stringVector newKind;
            newKind.push_back(qry.r[i][0].as<std::string>());
            newKind.push_back(qry.r[i][1].as<std::string>());
            comboBoxKinds << qry.r[i][1].as<std::string>().c_str();
            kinds.push_back(newKind);
        }
        ui->kindComboBox->addItems(comboBoxKinds);
    }
}

AddCustomerAddContactAddPhone::~AddCustomerAddContactAddPhone()
{
    delete ui;
}

void AddCustomerAddContactAddPhone::on_cancelButton_clicked()
{
    this->close();
}

void AddCustomerAddContactAddPhone::on_addButton_clicked()
{
    stringVector newPhone;
    newPhone.push_back(contact);
    std::string kindToAdd = "";
    for (int i = 0; i < (int)kinds.size(); ++i) {
        if (kinds.at(i).at(1) == ui->kindComboBox->currentText().toStdString()){
            kindToAdd = kinds.at(i).at(0);
            break;
        }
    }
    newPhone.push_back(kindToAdd);
    newPhone.push_back(ui->areaCodeLineEdit->text().toStdString());
    newPhone.push_back(ui->numberLineEdit->text().toStdString());
    newPhone.push_back(ui->extensionLineEdit->text().toStdString());
    std::cout << "New phone to add (contact, kind, area code, number, extension): ";
    std::cout << newPhone;
    std::cout << std::endl;
    phones->push_back(newPhone);
    emit CloseAndAdd();
    this->close();
}
