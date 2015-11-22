#ifndef MAINMENU_H
#define MAINMENU_H

#include "pintgd.h"
#include "Helper.h"
#include <QMainWindow>
#include <QCloseEvent>
#include "addcustomerwindow.h"

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
private slots:
    void on_customerAdd_clicked();
};

#endif // MAINMENU_H
