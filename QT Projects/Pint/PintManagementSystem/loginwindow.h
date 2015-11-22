#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "query.h"
#include "pintgd.h"
#include "Helper.h"
#include <QMainWindow>
#include "mainmenu.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_loginButton_clicked();
    void UserLoggedOut();

private:
    Ui::LoginWindow *ui;
    bool Login(SystemUser) const;
};

#endif // LOGINWINDOW_H
