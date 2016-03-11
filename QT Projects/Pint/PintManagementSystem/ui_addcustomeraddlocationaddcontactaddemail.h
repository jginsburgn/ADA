/********************************************************************************
** Form generated from reading UI file 'addcustomeraddlocationaddcontactaddemail.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H
#define UI_ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddCustomerAddLocationAddContactAddEmail
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *kindComboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;

    void setupUi(QDialog *AddCustomerAddLocationAddContactAddEmail)
    {
        if (AddCustomerAddLocationAddContactAddEmail->objectName().isEmpty())
            AddCustomerAddLocationAddContactAddEmail->setObjectName(QStringLiteral("AddCustomerAddLocationAddContactAddEmail"));
        AddCustomerAddLocationAddContactAddEmail->setWindowModality(Qt::WindowModal);
        AddCustomerAddLocationAddContactAddEmail->resize(310, 125);
        verticalLayout = new QVBoxLayout(AddCustomerAddLocationAddContactAddEmail);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddCustomerAddLocationAddContactAddEmail);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        addressLineEdit = new QLineEdit(AddCustomerAddLocationAddContactAddEmail);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        horizontalLayout->addWidget(addressLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(AddCustomerAddLocationAddContactAddEmail);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        kindComboBox = new QComboBox(AddCustomerAddLocationAddContactAddEmail);
        kindComboBox->setObjectName(QStringLiteral("kindComboBox"));

        horizontalLayout_3->addWidget(kindComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cancelButton = new QPushButton(AddCustomerAddLocationAddContactAddEmail);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addButton = new QPushButton(AddCustomerAddLocationAddContactAddEmail);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_2->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddCustomerAddLocationAddContactAddEmail);

        QMetaObject::connectSlotsByName(AddCustomerAddLocationAddContactAddEmail);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerAddLocationAddContactAddEmail)
    {
        AddCustomerAddLocationAddContactAddEmail->setWindowTitle(QApplication::translate("AddCustomerAddLocationAddContactAddEmail", "Dialog", 0));
        label->setText(QApplication::translate("AddCustomerAddLocationAddContactAddEmail", "Address:", 0));
        label_2->setText(QApplication::translate("AddCustomerAddLocationAddContactAddEmail", "Kind:", 0));
        cancelButton->setText(QApplication::translate("AddCustomerAddLocationAddContactAddEmail", "Cancel", 0));
        addButton->setText(QApplication::translate("AddCustomerAddLocationAddContactAddEmail", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerAddLocationAddContactAddEmail: public Ui_AddCustomerAddLocationAddContactAddEmail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERADDLOCATIONADDCONTACTADDEMAIL_H
