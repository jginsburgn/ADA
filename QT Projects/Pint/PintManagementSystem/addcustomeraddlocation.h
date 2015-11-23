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
    explicit AddCustomerAddLocation(QWidget * parent,
                                    stringMatrix * locations,
                                    stringMatrix * contacts,
                                    stringMatrix * phones,
                                    stringMatrix * emails);
    ~AddCustomerAddLocation();

public slots:
    void AddContact();

private slots:
    void on_cancelButton_clicked();
    void on_addContactButton_clicked();
    void on_addButton_clicked();

signals:
    void CloseAndAdd();

private:
    Ui::AddCustomerAddLocation *ui;
    AddCustomerAddLocationAddContact * addContactDialog;
    TableModel * contactsModel;
    stringMatrix * contacts;
    stringMatrix * phones;
    stringMatrix * emails;
    stringMatrix * locations;
    std::string thisLocation;
    stringMatrix * displayContacts = new stringMatrix();
};

#endif // ADDCUSTOMERADDLOCATION_H
