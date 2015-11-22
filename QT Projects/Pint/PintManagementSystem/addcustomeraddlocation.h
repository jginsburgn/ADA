#ifndef ADDCUSTOMERADDLOCATION_H
#define ADDCUSTOMERADDLOCATION_H

#include "addcustomeraddlocationaddcontact.h"
#include <QDialog>

namespace Ui {
class AddCustomerAddLocation;
}

class AddCustomerAddLocation : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerAddLocation(QWidget *parent = 0);
    ~AddCustomerAddLocation();

public slots:
    void AddContact();

private slots:
    void on_cancelButton_clicked();
    void on_addContactButton_clicked();

private:
    Ui::AddCustomerAddLocation *ui;
    AddCustomerAddLocationAddContact * addContactDialog;
    TableModel * contactsModel;
    stringMatrix * contacts = new stringMatrix();
    stringMatrix * phones = new stringMatrix();
    stringMatrix * emails = new stringMatrix();
    std::string location =  "1";
};

#endif // ADDCUSTOMERADDLOCATION_H
