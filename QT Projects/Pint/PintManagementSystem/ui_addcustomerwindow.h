/********************************************************************************
** Form generated from reading UI file 'addcustomerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERWINDOW_H
#define UI_ADDCUSTOMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCustomerWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *rfcLineEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *nameLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTableView *locationsTableView;
    QPushButton *addLocationButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTableView *contactsTableView;
    QPushButton *addContactButton;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addCustomerButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddCustomerWindow)
    {
        if (AddCustomerWindow->objectName().isEmpty())
            AddCustomerWindow->setObjectName(QStringLiteral("AddCustomerWindow"));
        AddCustomerWindow->resize(663, 473);
        centralwidget = new QWidget(AddCustomerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        rfcLineEdit = new QLineEdit(centralwidget);
        rfcLineEdit->setObjectName(QStringLiteral("rfcLineEdit"));

        horizontalLayout_2->addWidget(rfcLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        nameLineEdit = new QLineEdit(centralwidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        locationsTableView = new QTableView(centralwidget);
        locationsTableView->setObjectName(QStringLiteral("locationsTableView"));

        verticalLayout_2->addWidget(locationsTableView);

        addLocationButton = new QPushButton(centralwidget);
        addLocationButton->setObjectName(QStringLiteral("addLocationButton"));

        verticalLayout_2->addWidget(addLocationButton);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        contactsTableView = new QTableView(centralwidget);
        contactsTableView->setObjectName(QStringLiteral("contactsTableView"));

        verticalLayout->addWidget(contactsTableView);

        addContactButton = new QPushButton(centralwidget);
        addContactButton->setObjectName(QStringLiteral("addContactButton"));

        verticalLayout->addWidget(addContactButton);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_4);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        addCustomerButton = new QPushButton(centralwidget);
        addCustomerButton->setObjectName(QStringLiteral("addCustomerButton"));

        horizontalLayout_3->addWidget(addCustomerButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        AddCustomerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddCustomerWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 663, 22));
        AddCustomerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddCustomerWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AddCustomerWindow->setStatusBar(statusbar);

        retranslateUi(AddCustomerWindow);

        QMetaObject::connectSlotsByName(AddCustomerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddCustomerWindow)
    {
        AddCustomerWindow->setWindowTitle(QApplication::translate("AddCustomerWindow", "Add Customer", 0));
        label->setText(QApplication::translate("AddCustomerWindow", "RFC:", 0));
        label_2->setText(QApplication::translate("AddCustomerWindow", "Name:", 0));
        label_3->setText(QApplication::translate("AddCustomerWindow", "Locations", 0));
        addLocationButton->setText(QApplication::translate("AddCustomerWindow", "Add Location", 0));
        label_4->setText(QApplication::translate("AddCustomerWindow", "Contacts", 0));
        addContactButton->setText(QApplication::translate("AddCustomerWindow", "Add Contact", 0));
        cancelButton->setText(QApplication::translate("AddCustomerWindow", "Cancel", 0));
        addCustomerButton->setText(QApplication::translate("AddCustomerWindow", "Add Customer", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerWindow: public Ui_AddCustomerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERWINDOW_H
