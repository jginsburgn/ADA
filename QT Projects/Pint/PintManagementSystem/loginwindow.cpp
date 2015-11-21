#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    ui->statusBar->showMessage("Loging in...");
    SystemUser user = {ui->usernameLineEdit->text().toStdString(),
                      ui->passwordLineEdit->text().toStdString()};
    if (Login(user)) {
        ui->statusBar->clearMessage();
        this->setHidden(true);
        MainMenu *mainMenu = new MainMenu(this, user);
        connect(mainMenu, SIGNAL(UserLoggedOut()), this, SLOT(UserLoggedOut()));
        mainMenu->show();
    }
}

bool LoginWindow::Login(SystemUser) const{
    //pqxx::connection c()
    return true;
}

void LoginWindow::Logout() {
    this->setHidden(false);
}

void LoginWindow::UserLoggedOut() {
    this->setHidden(false);
    ui->statusBar->showMessage("Session closed. Login again to user Pint MS.");
}
