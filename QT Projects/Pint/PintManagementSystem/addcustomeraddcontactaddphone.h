#ifndef ADDCUSTOMERADDCONTACTADDPHONE_H
#define ADDCUSTOMERADDCONTACTADDPHONE_H

#include <QDialog>
#include "pintgd.h"
#include "query.h"

namespace Ui {
class AddCustomerAddContactAddPhone;
}

class AddCustomerAddContactAddPhone : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerAddContactAddPhone(QWidget * parent,
                                           stringMatrix * phones,
                                           std::string contact);
    ~AddCustomerAddContactAddPhone();

private slots:
    void on_cancelButton_clicked();
    void on_addButton_clicked();

signals:
    void CloseAndAdd();
    void CloseUponConnectionFailure();

private:
    Ui::AddCustomerAddContactAddPhone *ui;

    stringMatrix kinds;
    stringMatrix * phones;
    std::string contact;
};

#endif // ADDCUSTOMERADDCONTACTADDPHONE_H
