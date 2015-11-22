#ifndef ADDCUSTOMERWINDOW_H
#define ADDCUSTOMERWINDOW_H

#include "query.h"
#include "pintgd.h"
#include <QMainWindow>
#include <QAbstractTableModel>
#include "addcustomeraddlocation.h"

namespace Ui {
class AddCustomerWindow;
}

class AddCustomerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddCustomerWindow(QWidget *parent = 0);
    ~AddCustomerWindow();

private slots:
    void on_rfcLineEdit_textChanged(const QString &arg1);
    void on_nameLineEdit_textEdited(const QString &arg1);

    void on_addLocationButton_clicked();

private:
    Ui::AddCustomerWindow *ui;

    //New customer traits:
    std::string rfc;
    std::string name;
    stringVector locations;
    stringMatrix contacts; //Col 2 indicates "Direct" or "Through" location, if through,
                            //Col 1 indicates relation to location.
    stringMatrix phones; //Col 1 indicates relation to contact
    stringMatrix emails; //Col 1 indicates relation to contact

    bool verifyRFCUniqueness(const std::string & rfc);
    bool verifyNameUniqueness(const std::string & rfc);
};

#endif // ADDCUSTOMERWINDOW_H
