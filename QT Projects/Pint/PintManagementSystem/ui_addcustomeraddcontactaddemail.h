/********************************************************************************
** Form generated from reading UI file 'addcustomeraddcontactaddemail.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERADDCONTACTADDEMAIL_H
#define UI_ADDCUSTOMERADDCONTACTADDEMAIL_H

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

class Ui_AddCustomerAddContactAddEmail
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *kindComboBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;

    void setupUi(QDialog *AddCustomerAddContactAddEmail)
    {
        if (AddCustomerAddContactAddEmail->objectName().isEmpty())
            AddCustomerAddContactAddEmail->setObjectName(QStringLiteral("AddCustomerAddContactAddEmail"));
        AddCustomerAddContactAddEmail->setWindowModality(Qt::WindowModal);
        AddCustomerAddContactAddEmail->resize(286, 125);
        verticalLayout = new QVBoxLayout(AddCustomerAddContactAddEmail);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(AddCustomerAddContactAddEmail);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        addressLineEdit = new QLineEdit(AddCustomerAddContactAddEmail);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        horizontalLayout_2->addWidget(addressLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(AddCustomerAddContactAddEmail);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        kindComboBox = new QComboBox(AddCustomerAddContactAddEmail);
        kindComboBox->setObjectName(QStringLiteral("kindComboBox"));

        horizontalLayout->addWidget(kindComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cancelButton = new QPushButton(AddCustomerAddContactAddEmail);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        addButton = new QPushButton(AddCustomerAddContactAddEmail);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_3->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(AddCustomerAddContactAddEmail);

        QMetaObject::connectSlotsByName(AddCustomerAddContactAddEmail);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerAddContactAddEmail)
    {
        AddCustomerAddContactAddEmail->setWindowTitle(QApplication::translate("AddCustomerAddContactAddEmail", "Dialog", 0));
        label->setText(QApplication::translate("AddCustomerAddContactAddEmail", "Address:", 0));
        label_2->setText(QApplication::translate("AddCustomerAddContactAddEmail", "Kind:", 0));
        cancelButton->setText(QApplication::translate("AddCustomerAddContactAddEmail", "Cancel", 0));
        addButton->setText(QApplication::translate("AddCustomerAddContactAddEmail", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerAddContactAddEmail: public Ui_AddCustomerAddContactAddEmail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERADDCONTACTADDEMAIL_H
