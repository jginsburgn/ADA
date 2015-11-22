#ifndef ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H
#define ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H

#include <QDialog>

namespace Ui {
class AddCustomerAddLocationAddContactAddEmail;
}

class AddCustomerAddLocationAddContactAddEmail : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerAddLocationAddContactAddEmail(QWidget *parent = 0);
    ~AddCustomerAddLocationAddContactAddEmail();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::AddCustomerAddLocationAddContactAddEmail *ui;
};

#endif // ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H
