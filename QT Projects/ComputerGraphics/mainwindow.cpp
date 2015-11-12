#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->runButton->setText("Run :)");

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    scene->addLine(0, 0, 12, 100, outlinePen);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_runButton_clicked(){
    qDebug() << "Button pressed";
}

void MainWindow::mousePressEvent(QMouseEvent * event){
    qDebug() << "Mouse pressed";
}