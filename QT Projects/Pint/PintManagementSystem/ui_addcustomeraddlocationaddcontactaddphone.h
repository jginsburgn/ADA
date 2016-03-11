/********************************************************************************
** Form generated from reading UI file 'addcustomeraddlocationaddcontactaddphone.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERADDLOCATIONADDCONTACTADDPHONE_H
#define UI_ADDCUSTOMERADDLOCATIONADDCONTACTADDPHONE_H

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

class Ui_AddCustomerAddLocationAddContactAddPhone
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *areaCodeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *numberLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *extensionLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *kindComboBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;

    void setupUi(QDialog *AddCustomerAddLocationAddContactAddPhone)
    {
        if (AddCustomerAddLocationAddContactAddPhone->objectName().isEmpty())
            AddCustomerAddLocationAddContactAddPhone->setObjectName(QStringLiteral("AddCustomerAddLocationAddContactAddPhone"));
        AddCustomerAddLocationAddContactAddPhone->setWindowModality(Qt::WindowModal);
        AddCustomerAddLocationAddContactAddPhone->resize(318, 191);
        verticalLayout = new QVBoxLayout(AddCustomerAddLocationAddContactAddPhone);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddCustomerAddLocationAddContactAddPhone);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        areaCodeLineEdit = new QLineEdit(AddCustomerAddLocationAddContactAddPhone);
        areaCodeLineEdit->setObjectName(QStringLiteral("areaCodeLineEdit"));

        horizontalLayout->addWidget(areaCodeLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(AddCustomerAddLocationAddContactAddPhone);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        numberLineEdit = new QLineEdit(AddCustomerAddLocationAddContactAddPhone);
        numberLineEdit->setObjectName(QStringLiteral("numberLineEdit"));

        horizontalLayout_2->addWidget(numberLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(AddCustomerAddLocationAddContactAddPhone);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        extensionLineEdit = new QLineEdit(AddCustomerAddLocationAddContactAddPhone);
        extensionLineEdit->setObjectName(QStringLiteral("extensionLineEdit"));

        horizontalLayout_3->addWidget(extensionLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(AddCustomerAddLocationAddContactAddPhone);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        kindComboBox = new QComboBox(AddCustomerAddLocationAddContactAddPhone);
        kindComboBox->setObjectName(QStringLiteral("kindComboBox"));

        horizontalLayout_6->addWidget(kindComboBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cancelButton = new QPushButton(AddCustomerAddLocationAddContactAddPhone);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_4->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        addButton = new QPushButton(AddCustomerAddLocationAddContactAddPhone);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_4->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(AddCustomerAddLocationAddContactAddPhone);

        QMetaObject::connectSlotsByName(AddCustomerAddLocationAddContactAddPhone);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerAddLocationAddContactAddPhone)
    {
        AddCustomerAddLocationAddContactAddPhone->setWindowTitle(QApplication::translate("AddCustomerAddLocationAddContactAddPhone", "Dialog", 0));
        label->setText(QApplication::translate("AddCustomerAddLocationAddContactAddPhone", "Area Code:", 0));
        label_2->setText(QApplication::translate("AddCustomerAddLocationAddContactAddPhone", "Number:", 0));
        label_3->setText(QApplication::translate("AddCustomerAddLocationAddContactAddPhone", "Extension:", 0));
        label_4->setText(QApplication::translate("AddCustomerAddLocationAddContactAddPhone", "Kind:", 0));
        cancelButton->setText(QApplication::translate("AddCustomerAddLocationAddContactAddPhone", "Cancel", 0));
        addButton->setText(QApplication::translate("AddCustomerAddLocationAddContactAddPhone", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerAddLocationAddContactAddPhone: public Ui_AddCustomerAddLocationAddContactAddPhone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERADDLOCATIONADDCONTACTADDPHONE_H
