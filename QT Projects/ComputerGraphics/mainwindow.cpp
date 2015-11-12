#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

//    QBrush greenBrush(Qt::green);
//    QBrush blueBrush(Qt::blue);
//    QPen outlinePen(Qt::black);
//    outlinePen.setWidth(2);
//    scene->addLine(0, 0, 12, 100, outlinePen);

    DrawAxes();
    BuildComboBoxes();
}

MainWindow::~MainWindow(){
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

void MainWindow::DrawHorizontalTick(const float & pos){
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    scene->addLine(-TICK_LENGTH, pos, TICK_LENGTH, pos, outlinePen);
}

void MainWindow::DrawVerticalTick(const float & pos){
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    scene->addLine(pos, -TICK_LENGTH, pos, TICK_LENGTH, outlinePen);
}

void MainWindow::DrawAxes(){
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    scene->addLine(-1000, 0, 1000, 0, outlinePen); //X axis
    scene->addLine(0, -1000, 0, 1000, outlinePen); //Y axis
    scene->addText("(0, 0)");

    for (int i = 0; i < 10; ++i) {
        DrawVerticalTick(-100*i);
        DrawVerticalTick(100*i);
        DrawHorizontalTick(-100*i);
        DrawHorizontalTick(100*i);
    }

    QGraphicsTextItem * tick1 = scene->addText("(1, 0)");
    tick1->setPos(QPointF(100, 0));

    QGraphicsTextItem * tick2 = scene->addText("(0, 1)");
    tick2->setPos(QPointF(0, -100));
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
