#ifndef ADDCUSTOMERADDCONTACT_H
#define ADDCUSTOMERADDCONTACT_H

#include <QDialog>
#include "addcustomeraddcontactaddphone.h"
#include "addcustomeraddcontactaddemail.h"
#include "tablemodel.h"

namespace Ui {
class AddCustomerAddContact;
}

class AddCustomerAddContact : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerAddContact(QWidget * parent,
                                   stringMatrix * contacts,
                                   stringMatrix * phones,
                                   stringMatrix * emails);
    ~AddCustomerAddContact();

private slots:
    void on_cancelButton_clicked();
    void on_addButton_clicked();
    void on_addPhoneButton_clicked();
    void on_addEmailButton_clicked();

public slots:
    void AddPhone();
    void AddEmail();

signals:
    void CloseAndAdd();

private:
    Ui::AddCustomerAddContact *ui;

    AddCustomerAddContactAddPhone * phoneDialog;
    AddCustomerAddContactAddEmail * emailDialog;

    stringMatrix * phones;
    stringMatrix * emails;
    stringMatrix * contacts;
    std::string thisContact;
    stringMatrix * displayPhones = new stringMatrix();
    stringMatrix * displayEmails = new stringMatrix();
    TableModel * phonesModel;
    TableModel * emailsModel;
};

#endif // ADDCUSTOMERADDCONTACT_H
