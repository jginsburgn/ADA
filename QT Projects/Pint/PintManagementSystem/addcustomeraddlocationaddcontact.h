#ifndef ADDCUSTOMERADDLOCATIONADDCONTACT_H
#define ADDCUSTOMERADDLOCATIONADDCONTACT_H

#include "tablemodel.h"
#include "addcustomeraddlocationaddcontactaddemail.h"
#include "addcustomeraddlocationaddcontactaddphone.h"
#include <QDialog>

namespace Ui {
class AddCustomerAddLocationAddContact;
}

class AddCustomerAddLocationAddContact : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerAddLocationAddContact(QWidget *parent = 0);
    ~AddCustomerAddLocationAddContact();

private slots:
    void on_cancelButton_clicked();
    void on_addPhoneButton_clicked();
    void on_addEmailButton_clicked();

public slots:
    void PhoneAdded();
    void EmailAdded();

private:
    Ui::AddCustomerAddLocationAddContact *ui;
    stringMatrix * emails = new stringMatrix();
    stringMatrix * phones = new stringMatrix();
    std::string contact = "1";
    TableModel * phonesModel;
    TableModel * emailsModel;
    AddCustomerAddLocationAddContactAddEmail * emailDialog;
    AddCustomerAddLocationAddContactAddPhone * phoneDialog;
};

#endif // ADDCUSTOMERADDLOCATIONADDCONTACT_H
