#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    model = new Model(nullptr);
    ui->setupUi(this);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Helper::print("Reload Data...");
    model->ReloadData();
}
