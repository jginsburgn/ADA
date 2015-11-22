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
    explicit AddCustomerAddLocationAddContact(QWidget *parent,
                                              stringMatrix * emails,
                                              stringMatrix * phones,
                                              stringMatrix * contacts,
                                              std::string location);
    ~AddCustomerAddLocationAddContact();

private slots:
    void on_cancelButton_clicked();
    void on_addPhoneButton_clicked();
    void on_addEmailButton_clicked();
    void on_addButton_clicked();

public slots:
    void PhoneAdded();
    void EmailAdded();

signals:
    void CloseAndAdd();

private:
    Ui::AddCustomerAddLocationAddContact *ui;
    stringMatrix * displayPhones = new stringMatrix();
    stringMatrix * displayEmails = new stringMatrix();
    TableModel * phonesModel;
    TableModel * emailsModel;
    AddCustomerAddLocationAddContactAddEmail * emailDialog;
    AddCustomerAddLocationAddContactAddPhone * phoneDialog;

    stringMatrix * emails;
    stringMatrix * phones;
    stringMatrix * contacts;
    std::string location;
};

#endif // ADDCUSTOMERADDLOCATIONADDCONTACT_H
