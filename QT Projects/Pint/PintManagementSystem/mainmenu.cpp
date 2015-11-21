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
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::closeEvent(QCloseEvent *event) {
    //event->ignore(); /*This is to prevent closing the window*/
    emit UserLoggedOut();
}
