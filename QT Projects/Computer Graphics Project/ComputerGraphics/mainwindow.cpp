#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

//    QBrush greenBrush(Qt::green);
//    QBrush blueBrush(Qt::blue);
//    QPen outlinePen(Qt::black);
//    outlinePen.setWidth(2);
//    scene->addLine(0, 0, 12, 100, outlinePen);

    CleanPlane();
    BuildComboBoxes();
    PrepareUI();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::CleanPlane(){
    scene->clear();
    DrawAxes();
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

    for (int i = 1; i < 10; ++i) {
        std::string xPos = "(0, ";
        xPos.append(Helper::intToString(i));
        xPos.append(")");
        QGraphicsTextItem * posX = scene->addText(QString::fromStdString(xPos));
        posX->setPos(QPointF(i*100, 0));

        std::string xNeg = "(0, ";
        xNeg.append(Helper::intToString(-i));
        xNeg.append(")");
        QGraphicsTextItem * negX = scene->addText(QString::fromStdString(xNeg));
        negX->setPos(QPointF(-i*100, 0));

        std::string yPos = "(";
        yPos.append(Helper::intToString(-i));
        yPos.append(", 0)");
        QGraphicsTextItem * posY = scene->addText(QString::fromStdString(yPos));
        posY->setPos(QPointF(0, i*100));

        std::string yNeg = "(";
        yNeg.append(Helper::intToString(i));
        yNeg.append(", 0)");
        QGraphicsTextItem * negY = scene->addText(QString::fromStdString(yNeg));
        negY->setPos(QPointF(0, -i*100));
    }
}

void MainWindow::PrepareUI(){
    ui->figuresMenu->setCurrentIndex(-1);
    ui->drawStatusLabel->setText("Choose figure");
    ui->transformationsMenu->setCurrentIndex(-1);
    ui->transformStatusLabel->setText("Choose transformation");
}

void MainWindow::on_drawButton_clicked(){
    if (figureToDraw == FM_POLYGON) {
        std::string string = ui->additionalInfoDraw->text().toStdString();
        int value;
        if (Helper::stringIsNumber(string)) {
            value = std::atoi(string.c_str());
            CleanPlane();
            Figure newFigure = Figure::BuildPolygon(value);
            painter.DrawFigure(newFigure, scene);
            ui->drawStatusLabel->setText("Figure drawn");
            ui->additionalInfoDraw->setEnabled(false);
            figureToDraw = "";
        } else {
            ui->drawStatusLabel->setText("Invalid argument, Try again");
        }
    }
    else if (figureToDraw == FM_ARC){
        std::string string = ui->additionalInfoDraw->text().toStdString();
        int value;
        try {
            value = Helper::stringToFloat(string);
            CleanPlane();
            Figure newFigure = Figure::BuildArc(value);
            painter.DrawFigure(newFigure, scene);
            ui->drawStatusLabel->setText("Figure drawn");
            ui->additionalInfoDraw->setEnabled(false);
            figureToDraw = "";
        } catch (const char *) {
            ui->drawStatusLabel->setText("Invalid argument, Try again");
        }
    }
    else if (figureToDraw == FM_CUBE){
        CleanPlane();
        Figure newFigure = Figure::BuildCube();
        painter.DrawFigure(newFigure, scene);
        ui->drawStatusLabel->setText("Figure drawn");
        ui->additionalInfoDraw->setEnabled(false);
        figureToDraw = "";
    }
    else if (figureToDraw == FM_RECTANGULAR_PRISM){
        CleanPlane();
        Figure newFigure = Figure::BuildRectangularPrism();
        painter.DrawFigure(newFigure, scene);
        ui->drawStatusLabel->setText("Figure drawn");
        ui->additionalInfoDraw->setEnabled(false);
        figureToDraw = "";
    }
    else if (figureToDraw == FM_TRIANGULAR_PRISM){
        CleanPlane();
        Figure newFigure = Figure::BuildTriangularPrism();
        painter.DrawFigure(newFigure, scene);
        ui->drawStatusLabel->setText("Figure drawn");
        ui->additionalInfoDraw->setEnabled(false);
        figureToDraw = "";
    }
    else if (figureToDraw == FM_CONE){
        CleanPlane();
        Figure newFigure = Figure::BuildCone();
        painter.DrawFigure(newFigure, scene);
        ui->drawStatusLabel->setText("Figure drawn");
        ui->additionalInfoDraw->setEnabled(false);
        figureToDraw = "";
    }
}

void MainWindow::on_transformButton_clicked(){
    if (transformToApply == TM_ROTATION) {
        std::string string = ui->additionalInfoTransform->text().toStdString();
        float value;
        try {
            value = Helper::stringToFloat(string);
            CleanPlane();
            painter.RotateFigure(value);
            ui->transformStatusLabel->setText("Press to transform again");
        } catch (const char *) {
            ui->transformStatusLabel->setText("Invalid argument, Try again");
        }
    }
    else if (transformToApply == TM_X_TRANSLATION){
        std::string string = ui->additionalInfoTransform->text().toStdString();
        float value;
        try {
            value = Helper::stringToFloat(string);
            CleanPlane();
            painter.XTranslateFigure(100*value);
            ui->transformStatusLabel->setText("Press to transform again");
        } catch (const char *) {
            ui->transformStatusLabel->setText("Invalid argument, Try again");
        }
    }
    else if (transformToApply == TM_Y_TRANSLATION){
        std::string string = ui->additionalInfoTransform->text().toStdString();
        float value;
        try {
            value = Helper::stringToFloat(string);
            CleanPlane();
            painter.YTranslateFigure(-100*value);
            ui->transformStatusLabel->setText("Press to transform again");
        } catch (const char *) {
            ui->transformStatusLabel->setText("Invalid argument, Try again");
        }
    }
    else if (transformToApply == TM_X_REFLECTION){
        CleanPlane();
        painter.XReflectFigure();
    }
    else if (transformToApply == TM_Y_REFLECTION){
        CleanPlane();
        painter.YReflectFigure();
    }
    else if (transformToApply == TM_X_SCALING){
        std::string string = ui->additionalInfoTransform->text().toStdString();
        float value;
        try {
            value = Helper::stringToFloat(string);
            CleanPlane();
            painter.XScaleFigure(value);
            ui->transformStatusLabel->setText("Press to transform again");
        } catch (const char *) {
            ui->transformStatusLabel->setText("Invalid argument, Try again");
        }
    }
    else if (transformToApply == TM_Y_SCALING){
        std::string string = ui->additionalInfoTransform->text().toStdString();
        float value;
        try {
            value = Helper::stringToFloat(string);
            CleanPlane();
            painter.YScaleFigure(value);
            ui->transformStatusLabel->setText("Press to transform again");
        } catch (const char *) {
            ui->transformStatusLabel->setText("Invalid argument, Try again");
        }
    }
}

void MainWindow::on_figuresMenu_activated(const QString &arg1){
    if (arg1 == FM_POLYGON) {
        figureToDraw = FM_POLYGON;
        ui->additionalInfoDraw->setEnabled(true);
        ui->drawStatusLabel->setText("Enter sides of polygon");
    }
    else if (arg1 == FM_ARC){
        figureToDraw = FM_ARC;
        ui->additionalInfoDraw->setEnabled(true);
        ui->drawStatusLabel->setText("Enter angle of arc in degres");
    }
    else if (arg1 == FM_CUBE){
        figureToDraw = FM_CUBE;
        ui->additionalInfoDraw->setEnabled(false);
        ui->drawStatusLabel->setText("No additional information needed");
    }
    else if (arg1 == FM_RECTANGULAR_PRISM){
        figureToDraw = FM_RECTANGULAR_PRISM;
        ui->additionalInfoDraw->setEnabled(false);
        ui->drawStatusLabel->setText("No additional information needed");
    }
    else if (arg1 == FM_TRIANGULAR_PRISM){
        figureToDraw = FM_TRIANGULAR_PRISM;
        ui->additionalInfoDraw->setEnabled(false);
        ui->drawStatusLabel->setText("No additional information needed");
    }
    else if (arg1 == FM_CONE){
        figureToDraw = FM_CONE;
        ui->additionalInfoDraw->setEnabled(false);
        ui->drawStatusLabel->setText("No additional information needed");
    }
}

void MainWindow::on_transformationsMenu_activated(const QString &arg1){
    if (arg1 == TM_ROTATION) {
        transformToApply = TM_ROTATION;
        ui->additionalInfoTransform->setEnabled(true);
        ui->transformStatusLabel->setText("Enter amount to rotate in degrees");
    }
    else if (arg1 == TM_X_TRANSLATION){
        transformToApply = TM_X_TRANSLATION;
        ui->additionalInfoTransform->setEnabled(true);
        ui->transformStatusLabel->setText("Enter amount to translate in units");
    }
    else if (arg1 == TM_Y_TRANSLATION){
        transformToApply = TM_Y_TRANSLATION;
        ui->additionalInfoTransform->setEnabled(true);
        ui->transformStatusLabel->setText("Enter amount to translate in units");
    }
    else if (arg1 == TM_X_REFLECTION){
        transformToApply = TM_X_REFLECTION;
        ui->additionalInfoTransform->setEnabled(false);
        ui->transformStatusLabel->setText("No additional information needed");
    }
    else if (arg1 == TM_Y_REFLECTION){
        transformToApply = TM_Y_REFLECTION;
        ui->additionalInfoTransform->setEnabled(false);
        ui->transformStatusLabel->setText("No additional information needed");
    }
    else if (arg1 == TM_X_SCALING){
        transformToApply = TM_X_SCALING;
        ui->additionalInfoTransform->setEnabled(true);
        ui->transformStatusLabel->setText("Enter scale factor in units");
    }
    else if (arg1 == TM_Y_SCALING){
        transformToApply = TM_Y_SCALING;
        ui->additionalInfoTransform->setEnabled(true);
        ui->transformStatusLabel->setText("Enter scale factor in units");
    }
}
