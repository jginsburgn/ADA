/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *customerAdd;
    QPushButton *customerEdit;
    QPushButton *quoteAdd;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *supplierAdd;
    QPushButton *supplierEdit;
    QPushButton *productAdd;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *logOut;
    QSpacerItem *horizontalSpacer;
    QPushButton *userAdd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(314, 248);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        customerAdd = new QPushButton(centralwidget);
        customerAdd->setObjectName(QStringLiteral("customerAdd"));

        horizontalLayout_2->addWidget(customerAdd);

        customerEdit = new QPushButton(centralwidget);
        customerEdit->setObjectName(QStringLiteral("customerEdit"));

        horizontalLayout_2->addWidget(customerEdit);

        quoteAdd = new QPushButton(centralwidget);
        quoteAdd->setObjectName(QStringLiteral("quoteAdd"));

        horizontalLayout_2->addWidget(quoteAdd);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        supplierAdd = new QPushButton(centralwidget);
        supplierAdd->setObjectName(QStringLiteral("supplierAdd"));
        supplierAdd->setEnabled(false);

        horizontalLayout->addWidget(supplierAdd);

        supplierEdit = new QPushButton(centralwidget);
        supplierEdit->setObjectName(QStringLiteral("supplierEdit"));
        supplierEdit->setEnabled(false);

        horizontalLayout->addWidget(supplierEdit);

        productAdd = new QPushButton(centralwidget);
        productAdd->setObjectName(QStringLiteral("productAdd"));
        productAdd->setEnabled(false);

        horizontalLayout->addWidget(productAdd);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        logOut = new QPushButton(centralwidget);
        logOut->setObjectName(QStringLiteral("logOut"));

        horizontalLayout_3->addWidget(logOut);

        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        userAdd = new QPushButton(centralwidget);
        userAdd->setObjectName(QStringLiteral("userAdd"));
        userAdd->setEnabled(false);

        horizontalLayout_3->addWidget(userAdd);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 314, 22));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "PMS Main Menu", 0));
        label->setText(QApplication::translate("MainMenu", "Customers", 0));
        customerAdd->setText(QApplication::translate("MainMenu", "Add", 0));
        customerEdit->setText(QApplication::translate("MainMenu", "View/Edit", 0));
        quoteAdd->setText(QApplication::translate("MainMenu", "Add Quote", 0));
        label_2->setText(QApplication::translate("MainMenu", "Suppliers", 0));
        supplierAdd->setText(QApplication::translate("MainMenu", "Add", 0));
        supplierEdit->setText(QApplication::translate("MainMenu", "View/Edit", 0));
        productAdd->setText(QApplication::translate("MainMenu", "Add Product", 0));
        logOut->setText(QApplication::translate("MainMenu", "Log Out", 0));
        userAdd->setText(QApplication::translate("MainMenu", "Add System User", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
