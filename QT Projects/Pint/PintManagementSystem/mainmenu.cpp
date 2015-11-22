#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::MainMenu(QWidget * parent, SystemUser newUser) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    user = newUser;
    std::string message = "Logged in as " + newUser.username + "." ;
    ui->statusbar->showMessage(message.c_str());
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::closeEvent(QCloseEvent * /*event*/) {
    //event->ignore(); /*This is to prevent closing the window*/
    emit UserLoggedOut();
}

void MainMenu::on_customerAdd_clicked()
{
    AddCustomerWindow * addCustomerWindow = new AddCustomerWindow(this);
    addCustomerWindow->show();
}
