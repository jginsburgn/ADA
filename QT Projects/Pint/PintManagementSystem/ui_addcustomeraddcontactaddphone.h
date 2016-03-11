/********************************************************************************
** Form generated from reading UI file 'addcustomeraddcontactaddphone.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERADDCONTACTADDPHONE_H
#define UI_ADDCUSTOMERADDCONTACTADDPHONE_H

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

class Ui_AddCustomerAddContactAddPhone
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *areaCodeLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *numberLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *extensionLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *kindComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;

    void setupUi(QDialog *AddCustomerAddContactAddPhone)
    {
        if (AddCustomerAddContactAddPhone->objectName().isEmpty())
            AddCustomerAddContactAddPhone->setObjectName(QStringLiteral("AddCustomerAddContactAddPhone"));
        AddCustomerAddContactAddPhone->setWindowModality(Qt::WindowModal);
        AddCustomerAddContactAddPhone->resize(301, 191);
        verticalLayout = new QVBoxLayout(AddCustomerAddContactAddPhone);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(AddCustomerAddContactAddPhone);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        areaCodeLineEdit = new QLineEdit(AddCustomerAddContactAddPhone);
        areaCodeLineEdit->setObjectName(QStringLiteral("areaCodeLineEdit"));

        horizontalLayout_5->addWidget(areaCodeLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(AddCustomerAddContactAddPhone);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        numberLineEdit = new QLineEdit(AddCustomerAddContactAddPhone);
        numberLineEdit->setObjectName(QStringLiteral("numberLineEdit"));

        horizontalLayout_4->addWidget(numberLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(AddCustomerAddContactAddPhone);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        extensionLineEdit = new QLineEdit(AddCustomerAddContactAddPhone);
        extensionLineEdit->setObjectName(QStringLiteral("extensionLineEdit"));

        horizontalLayout_3->addWidget(extensionLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(AddCustomerAddContactAddPhone);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        kindComboBox = new QComboBox(AddCustomerAddContactAddPhone);
        kindComboBox->setObjectName(QStringLiteral("kindComboBox"));

        horizontalLayout_2->addWidget(kindComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cancelButton = new QPushButton(AddCustomerAddContactAddPhone);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addButton = new QPushButton(AddCustomerAddContactAddPhone);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddCustomerAddContactAddPhone);

        QMetaObject::connectSlotsByName(AddCustomerAddContactAddPhone);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerAddContactAddPhone)
    {
        AddCustomerAddContactAddPhone->setWindowTitle(QApplication::translate("AddCustomerAddContactAddPhone", "Dialog", 0));
        label->setText(QApplication::translate("AddCustomerAddContactAddPhone", "Area Code:", 0));
        label_2->setText(QApplication::translate("AddCustomerAddContactAddPhone", "Number:", 0));
        label_3->setText(QApplication::translate("AddCustomerAddContactAddPhone", "Extension:", 0));
        label_4->setText(QApplication::translate("AddCustomerAddContactAddPhone", "Kind:", 0));
        cancelButton->setText(QApplication::translate("AddCustomerAddContactAddPhone", "Cancel", 0));
        addButton->setText(QApplication::translate("AddCustomerAddContactAddPhone", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerAddContactAddPhone: public Ui_AddCustomerAddContactAddPhone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERADDCONTACTADDPHONE_H
