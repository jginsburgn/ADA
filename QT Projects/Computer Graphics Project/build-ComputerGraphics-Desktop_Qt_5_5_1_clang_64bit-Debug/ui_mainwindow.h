/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *generalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *drawLayout;
    QComboBox *figuresMenu;
    QLabel *drawStatusLabel;
    QLineEdit *additionalInfoDraw;
    QPushButton *drawButton;
    QSpacerItem *drawHorizontalSpacer;
    QHBoxLayout *transformLayout;
    QComboBox *transformationsMenu;
    QLabel *transformStatusLabel;
    QLineEdit *additionalInfoTransform;
    QPushButton *transformButton;
    QSpacerItem *transformHorizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(832, 573);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 12, 811, 551));
        generalLayout = new QVBoxLayout(layoutWidget);
        generalLayout->setSpacing(6);
        generalLayout->setContentsMargins(11, 11, 11, 11);
        generalLayout->setObjectName(QStringLiteral("generalLayout"));
        generalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        generalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(layoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        generalLayout->addWidget(graphicsView);

        drawLayout = new QHBoxLayout();
        drawLayout->setSpacing(6);
        drawLayout->setObjectName(QStringLiteral("drawLayout"));
        figuresMenu = new QComboBox(layoutWidget);
        figuresMenu->setObjectName(QStringLiteral("figuresMenu"));

        drawLayout->addWidget(figuresMenu);

        drawStatusLabel = new QLabel(layoutWidget);
        drawStatusLabel->setObjectName(QStringLiteral("drawStatusLabel"));

        drawLayout->addWidget(drawStatusLabel);

        additionalInfoDraw = new QLineEdit(layoutWidget);
        additionalInfoDraw->setObjectName(QStringLiteral("additionalInfoDraw"));
        additionalInfoDraw->setEnabled(false);

        drawLayout->addWidget(additionalInfoDraw);

        drawButton = new QPushButton(layoutWidget);
        drawButton->setObjectName(QStringLiteral("drawButton"));

        drawLayout->addWidget(drawButton);

        drawHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        drawLayout->addItem(drawHorizontalSpacer);


        generalLayout->addLayout(drawLayout);

        transformLayout = new QHBoxLayout();
        transformLayout->setSpacing(6);
        transformLayout->setObjectName(QStringLiteral("transformLayout"));
        transformationsMenu = new QComboBox(layoutWidget);
        transformationsMenu->setObjectName(QStringLiteral("transformationsMenu"));

        transformLayout->addWidget(transformationsMenu);

        transformStatusLabel = new QLabel(layoutWidget);
        transformStatusLabel->setObjectName(QStringLiteral("transformStatusLabel"));

        transformLayout->addWidget(transformStatusLabel);

        additionalInfoTransform = new QLineEdit(layoutWidget);
        additionalInfoTransform->setObjectName(QStringLiteral("additionalInfoTransform"));
        additionalInfoTransform->setEnabled(false);

        transformLayout->addWidget(additionalInfoTransform);

        transformButton = new QPushButton(layoutWidget);
        transformButton->setObjectName(QStringLiteral("transformButton"));

        transformLayout->addWidget(transformButton);

        transformHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        transformLayout->addItem(transformHorizontalSpacer);


        generalLayout->addLayout(transformLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Computer Graphics beta", 0));
        drawStatusLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        drawButton->setText(QApplication::translate("MainWindow", "Draw", 0));
        transformStatusLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        transformButton->setText(QApplication::translate("MainWindow", "Transform", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
