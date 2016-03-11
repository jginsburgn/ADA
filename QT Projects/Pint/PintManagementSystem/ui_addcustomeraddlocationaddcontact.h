/********************************************************************************
** Form generated from reading UI file 'addcustomeraddlocationaddcontact.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERADDLOCATIONADDCONTACT_H
#define UI_ADDCUSTOMERADDLOCATIONADDCONTACT_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddCustomerAddLocationAddContact
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *surnamesLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTableView *phonesTableView;
    QPushButton *addPhoneButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTableView *emailsTableView;
    QPushButton *addEmailButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;

    void setupUi(QDialog *AddCustomerAddLocationAddContact)
    {
        if (AddCustomerAddLocationAddContact->objectName().isEmpty())
            AddCustomerAddLocationAddContact->setObjectName(QStringLiteral("AddCustomerAddLocationAddContact"));
        AddCustomerAddLocationAddContact->setWindowModality(Qt::WindowModal);
        AddCustomerAddLocationAddContact->resize(533, 371);
        verticalLayout_3 = new QVBoxLayout(AddCustomerAddLocationAddContact);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(AddCustomerAddLocationAddContact);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nameLineEdit = new QLineEdit(AddCustomerAddLocationAddContact);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout_2->addWidget(nameLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(AddCustomerAddLocationAddContact);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        surnamesLineEdit = new QLineEdit(AddCustomerAddLocationAddContact);
        surnamesLineEdit->setObjectName(QStringLiteral("surnamesLineEdit"));

        horizontalLayout->addWidget(surnamesLineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(AddCustomerAddLocationAddContact);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        phonesTableView = new QTableView(AddCustomerAddLocationAddContact);
        phonesTableView->setObjectName(QStringLiteral("phonesTableView"));

        verticalLayout_2->addWidget(phonesTableView);

        addPhoneButton = new QPushButton(AddCustomerAddLocationAddContact);
        addPhoneButton->setObjectName(QStringLiteral("addPhoneButton"));

        verticalLayout_2->addWidget(addPhoneButton);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_4 = new QLabel(AddCustomerAddLocationAddContact);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        emailsTableView = new QTableView(AddCustomerAddLocationAddContact);
        emailsTableView->setObjectName(QStringLiteral("emailsTableView"));

        verticalLayout->addWidget(emailsTableView);

        addEmailButton = new QPushButton(AddCustomerAddLocationAddContact);
        addEmailButton->setObjectName(QStringLiteral("addEmailButton"));

        verticalLayout->addWidget(addEmailButton);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cancelButton = new QPushButton(AddCustomerAddLocationAddContact);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        addButton = new QPushButton(AddCustomerAddLocationAddContact);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_3->addWidget(addButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label->raise();
        nameLineEdit->raise();
        surnamesLineEdit->raise();
        label_2->raise();
        nameLineEdit->raise();
        phonesTableView->raise();
        emailsTableView->raise();
        label_3->raise();
        label_4->raise();
        addPhoneButton->raise();
        addEmailButton->raise();
        addButton->raise();
        cancelButton->raise();

        retranslateUi(AddCustomerAddLocationAddContact);

        QMetaObject::connectSlotsByName(AddCustomerAddLocationAddContact);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerAddLocationAddContact)
    {
        AddCustomerAddLocationAddContact->setWindowTitle(QApplication::translate("AddCustomerAddLocationAddContact", "Dialog", 0));
        label->setText(QApplication::translate("AddCustomerAddLocationAddContact", "Name:", 0));
        label_2->setText(QApplication::translate("AddCustomerAddLocationAddContact", "Surnames:", 0));
        label_3->setText(QApplication::translate("AddCustomerAddLocationAddContact", "Phones", 0));
        addPhoneButton->setText(QApplication::translate("AddCustomerAddLocationAddContact", "Add Phone", 0));
        label_4->setText(QApplication::translate("AddCustomerAddLocationAddContact", "Emails", 0));
        addEmailButton->setText(QApplication::translate("AddCustomerAddLocationAddContact", "Add Email", 0));
        cancelButton->setText(QApplication::translate("AddCustomerAddLocationAddContact", "Cancel", 0));
        addButton->setText(QApplication::translate("AddCustomerAddLocationAddContact", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerAddLocationAddContact: public Ui_AddCustomerAddLocationAddContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERADDLOCATIONADDCONTACT_H
