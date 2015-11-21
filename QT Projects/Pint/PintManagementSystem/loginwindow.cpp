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
    std::string connDetails = "dbname=" + database + " host=" + host + " user=" +
            username + " password = " + password;
    try {
        pqxx::connection conn(connDetails.c_str());
        pqxx::work txn(conn);
        pqxx::result res = txn.exec("select * "
                           "from system_users "
                           "where username=" + txn.quote(user.username)
                           + "and a_password=" + txn.quote(user.password));
        if (res.size() == 1) return true;
    }
    catch (PGSTD::runtime_error e) {
        ui->statusBar->showMessage(connectionError.c_str());
    }
    catch (PGSTD::logic_error e) {
        ui->statusBar->showMessage(connectionError.c_str());
    }
    return false;
}

void LoginWindow::Logout() {
    this->setHidden(false);
}

void LoginWindow::UserLoggedOut() {
    this->setHidden(false);
    ui->statusBar->showMessage(sessionFinished.c_str());
}
