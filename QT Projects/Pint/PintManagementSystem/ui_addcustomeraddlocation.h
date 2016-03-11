/********************************************************************************
** Form generated from reading UI file 'addcustomeraddlocation.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERADDLOCATION_H
#define UI_ADDCUSTOMERADDLOCATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddCustomerAddLocation
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *addressLineEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTableView *contactsTableView;
    QPushButton *addContactButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;

    void setupUi(QDialog *AddCustomerAddLocation)
    {
        if (AddCustomerAddLocation->objectName().isEmpty())
            AddCustomerAddLocation->setObjectName(QStringLiteral("AddCustomerAddLocation"));
        AddCustomerAddLocation->setWindowModality(Qt::WindowModal);
        AddCustomerAddLocation->resize(403, 323);
        verticalLayout_3 = new QVBoxLayout(AddCustomerAddLocation);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(AddCustomerAddLocation);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        addressLineEdit = new QLineEdit(AddCustomerAddLocation);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        horizontalLayout_2->addWidget(addressLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(AddCustomerAddLocation);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        contactsTableView = new QTableView(AddCustomerAddLocation);
        contactsTableView->setObjectName(QStringLiteral("contactsTableView"));

        verticalLayout->addWidget(contactsTableView);

        addContactButton = new QPushButton(AddCustomerAddLocation);
        addContactButton->setObjectName(QStringLiteral("addContactButton"));

        verticalLayout->addWidget(addContactButton);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cancelButton = new QPushButton(AddCustomerAddLocation);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        horizontalLayout->addLayout(horizontalLayout_3);

        addButton = new QPushButton(AddCustomerAddLocation);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(AddCustomerAddLocation);

        QMetaObject::connectSlotsByName(AddCustomerAddLocation);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerAddLocation)
    {
        AddCustomerAddLocation->setWindowTitle(QApplication::translate("AddCustomerAddLocation", "Add Location", 0));
        label->setText(QApplication::translate("AddCustomerAddLocation", "Address:", 0));
        label_2->setText(QApplication::translate("AddCustomerAddLocation", "Contacts", 0));
        addContactButton->setText(QApplication::translate("AddCustomerAddLocation", "Add Contact", 0));
        cancelButton->setText(QApplication::translate("AddCustomerAddLocation", "Cancel", 0));
        addButton->setText(QApplication::translate("AddCustomerAddLocation", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerAddLocation: public Ui_AddCustomerAddLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERADDLOCATION_H
