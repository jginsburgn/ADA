#ifndef ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H
#define ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H

#include "pintgd.h"
#include "query.h"
#include <QDialog>

namespace Ui {
class AddCustomerAddLocationAddContactAddEmail;
}

class AddCustomerAddLocationAddContactAddEmail : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerAddLocationAddContactAddEmail(QWidget * parent, stringMatrix * newEmails, const std::string & contact);
    ~AddCustomerAddLocationAddContactAddEmail();

private slots:
    void on_cancelButton_clicked();
    void on_addButton_clicked();

signals:
    void CloseUponConnectionFailure();
    void CloseAndAdd();

private:
    stringMatrix * emails;
    std::string contact;
    stringMatrix kinds;
    Ui::AddCustomerAddLocationAddContactAddEmail *ui;
};

#endif // ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H
