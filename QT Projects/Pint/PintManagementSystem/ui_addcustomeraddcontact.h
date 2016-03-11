/********************************************************************************
** Form generated from reading UI file 'addcustomeraddcontact.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERADDCONTACT_H
#define UI_ADDCUSTOMERADDCONTACT_H

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

class Ui_AddCustomerAddContact
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_2;
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

    void setupUi(QDialog *AddCustomerAddContact)
    {
        if (AddCustomerAddContact->objectName().isEmpty())
            AddCustomerAddContact->setObjectName(QStringLiteral("AddCustomerAddContact"));
        AddCustomerAddContact->setWindowModality(Qt::WindowModal);
        AddCustomerAddContact->resize(489, 359);
        verticalLayout_3 = new QVBoxLayout(AddCustomerAddContact);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddCustomerAddContact);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(AddCustomerAddContact);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(AddCustomerAddContact);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        surnamesLineEdit = new QLineEdit(AddCustomerAddContact);
        surnamesLineEdit->setObjectName(QStringLiteral("surnamesLineEdit"));

        horizontalLayout_2->addWidget(surnamesLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(AddCustomerAddContact);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        phonesTableView = new QTableView(AddCustomerAddContact);
        phonesTableView->setObjectName(QStringLiteral("phonesTableView"));

        verticalLayout_2->addWidget(phonesTableView);

        addPhoneButton = new QPushButton(AddCustomerAddContact);
        addPhoneButton->setObjectName(QStringLiteral("addPhoneButton"));

        verticalLayout_2->addWidget(addPhoneButton);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_4 = new QLabel(AddCustomerAddContact);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        emailsTableView = new QTableView(AddCustomerAddContact);
        emailsTableView->setObjectName(QStringLiteral("emailsTableView"));

        verticalLayout->addWidget(emailsTableView);

        addEmailButton = new QPushButton(AddCustomerAddContact);
        addEmailButton->setObjectName(QStringLiteral("addEmailButton"));

        verticalLayout->addWidget(addEmailButton);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cancelButton = new QPushButton(AddCustomerAddContact);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        addButton = new QPushButton(AddCustomerAddContact);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_3->addWidget(addButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(AddCustomerAddContact);

        QMetaObject::connectSlotsByName(AddCustomerAddContact);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerAddContact)
    {
        AddCustomerAddContact->setWindowTitle(QApplication::translate("AddCustomerAddContact", "Dialog", 0));
        label->setText(QApplication::translate("AddCustomerAddContact", "Name:", 0));
        label_2->setText(QApplication::translate("AddCustomerAddContact", "Surnames:", 0));
        label_3->setText(QApplication::translate("AddCustomerAddContact", "Phones", 0));
        addPhoneButton->setText(QApplication::translate("AddCustomerAddContact", "Add Phone", 0));
        label_4->setText(QApplication::translate("AddCustomerAddContact", "Emails", 0));
        addEmailButton->setText(QApplication::translate("AddCustomerAddContact", "Add Email", 0));
        cancelButton->setText(QApplication::translate("AddCustomerAddContact", "Cancel", 0));
        addButton->setText(QApplication::translate("AddCustomerAddContact", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerAddContact: public Ui_AddCustomerAddContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERADDCONTACT_H
