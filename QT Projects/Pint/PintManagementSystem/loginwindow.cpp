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
    ui->statusBar->showMessage(loggingIn.c_str());
    SystemUser user = {ui->usernameLineEdit->text().toStdString(),
                      ui->passwordLineEdit->text().toStdString()};
    if (Login(user)) {
        ui->statusBar->clearMessage();
        this->setHidden(true);
        MainMenu *mainMenu = new MainMenu(this, user);
        connect(mainMenu, SIGNAL(UserLoggedOut()), this, SLOT(UserLoggedOut()));
        mainMenu->show();
    }
    else if (ui->statusBar->currentMessage().toStdString() != connectionError)
        ui->statusBar->showMessage(loginFailed.c_str());
}

bool LoginWindow::Login(SystemUser user) const{
    std::stringstream qryss;
    qryss << "select * " <<
           "from system_users " <<
           "where username=" << pg::quote(user.username) <<
           " and a_password=" << pg::quote(user.password);
    Query qry(qryss.str());
    if (qry.failed) {
        ui->statusBar->showMessage(qry.message.c_str());
        return false;
    }
    else {
        if (qry.r.size() != 1) {
            ui->statusBar->showMessage(loginFailed.c_str());
        }
        else return true;
    }
    return false;
}

void LoginWindow::UserLoggedOut() {
    this->setHidden(false);
    ui->statusBar->showMessage(sessionFinished.c_str());
}
