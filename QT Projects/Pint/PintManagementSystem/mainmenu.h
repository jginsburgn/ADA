#ifndef MAINMENU_H
#define MAINMENU_H

#include "Helper.h"
#include <pqxx/pqxx>
#include <QMainWindow>
#include <QCloseEvent>

struct SystemUser {
    std::string username;
    std::string password;
};

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    MainMenu(QWidget *, SystemUser);
    ~MainMenu();

signals:
    void UserLoggedOut();

private:
    Ui::MainMenu *ui;
    SystemUser user;

protected:
    void closeEvent(QCloseEvent * event) override;
};

#endif // MAINMENU_H
