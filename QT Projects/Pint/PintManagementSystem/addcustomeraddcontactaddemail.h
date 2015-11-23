#ifndef ADDCUSTOMERADDCONTACTADDEMAIL_H
#define ADDCUSTOMERADDCONTACTADDEMAIL_H

#include <QDialog>
#include "pintgd.h"
#include "query.h"

namespace Ui {
class AddCustomerAddContactAddEmail;
}

class AddCustomerAddContactAddEmail : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerAddContactAddEmail(QWidget * parent,
                                           stringMatrix * emails,
                                           std::string contact);
    ~AddCustomerAddContactAddEmail();

private slots:
    void on_cancelButton_clicked();
    void on_addButton_clicked();

signals:
    void CloseAndAdd();
    void CloseUponConnectionFailure();

private:
    Ui::AddCustomerAddContactAddEmail *ui;

    stringMatrix kinds;
    stringMatrix * emails;
    std::string contact;
};

#endif // ADDCUSTOMERADDCONTACTADDEMAIL_H
