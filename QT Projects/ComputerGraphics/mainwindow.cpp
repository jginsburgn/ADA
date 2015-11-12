#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    BuildComboBoxes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BuildComboBoxes(){

    QStringList figureOptions;
    figureOptions << FM_POLYGON;
    figureOptions << FM_ARC;
    figureOptions << FM_CUBE;
    figureOptions << FM_RECTANGULAR_PRISM;
    figureOptions << FM_TRIANGULAR_PRISM;
    figureOptions << FM_CONE;

    ui->figuresMenu->addItems(figureOptions);

    QStringList transformOptions;
    transformOptions << TM_ROTATION;
    transformOptions << TM_X_TRANSLATION;
    transformOptions << TM_Y_TRANSLATION;
    transformOptions << TM_X_REFLECTION;
    transformOptions << TM_Y_REFLECTION;
    transformOptions << TM_X_SCALING;
    transformOptions << TM_Y_SCALING;

    ui->transformationsMenu->addItems(transformOptions);
}

void MainWindow::DrawAxes(){
    scene->add
}

void MainWindow::on_drawButton_clicked()
{

}

void MainWindow::on_transformButton_clicked()
{

}

void MainWindow::on_figuresMenu_activated(const QString &arg1)
{

}

void MainWindow::on_transformationsMenu_activated(const QString &arg1)
{

}
