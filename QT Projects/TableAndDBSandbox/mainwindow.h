#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Helper.h"
#include "GeneralQt.h"
#include <QMainWindow>
#include "model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //My variables
    Model *model;
};

#endif // MAINWINDOW_H
