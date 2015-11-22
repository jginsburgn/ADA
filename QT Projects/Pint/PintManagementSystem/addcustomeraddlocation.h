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

private slots:
    void on_cancelButton_clicked();

    void on_addContactButton_clicked();

private:
    Ui::AddCustomerAddLocation *ui;
};

#endif // ADDCUSTOMERADDLOCATION_H
