#ifndef ADDCUSTOMERADDLOCATIONADDCONTACTADDPHONE_H
#define ADDCUSTOMERADDLOCATIONADDCONTACTADDPHONE_H

#include "pintgd.h"
#include "query.h"
#include <QDialog>

namespace Ui {
class AddCustomerAddLocationAddContactAddPhone;
}

class AddCustomerAddLocationAddContactAddPhone : public QDialog
{
    Q_OBJECT

public:
    AddCustomerAddLocationAddContactAddPhone(QWidget * parent, stringMatrix * phones, const std::string & contact);
    ~AddCustomerAddLocationAddContactAddPhone();

private slots:
    void on_cancelButton_clicked();
    void on_addButton_clicked();

signals:
    void CloseUponConnectionFailure();

private:
    stringMatrix * phones;
    std::string contact;
    stringMatrix kinds;
    Ui::AddCustomerAddLocationAddContactAddPhone *ui;
};

#endif // ADDCUSTOMERADDLOCATIONADDCONTACTADDPHONE_H
