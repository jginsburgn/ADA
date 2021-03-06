#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>

#include "Painter.h"
#include "Helper.h"


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
    void on_drawButton_clicked();
    void on_transformButton_clicked();
    void on_figuresMenu_activated(const QString &arg1);
    void on_transformationsMenu_activated(const QString &arg1);

private:
    const QString FM_POLYGON = "n Sided Polygon";
    const QString FM_ARC = "x Angled Arc";
    const QString FM_CUBE = "Cube";
    const QString FM_RECTANGULAR_PRISM = "Rectangular Prism";
    const QString FM_TRIANGULAR_PRISM = "Triangular Prism";
    const QString FM_CONE = "Cone";

    const QString TM_ROTATION = "Rotation";
    const QString TM_X_TRANSLATION = "x Translation";
    const QString TM_Y_TRANSLATION = "y Translation";
    const QString TM_X_REFLECTION = "x Reflection";
    const QString TM_Y_REFLECTION = "y Reflection";
    const QString TM_X_SCALING = "x Scaling";
    const QString TM_Y_SCALING = "y Scaling";

    const float TICK_LENGTH = 5;
    
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Painter painter;
    QString figureToDraw;
    QString transformToApply;

    void DrawVerticalTick(const float & pos);
    void DrawHorizontalTick(const float & pos);
    void DrawAxes();
    void BuildComboBoxes();
    void PrepareUI();
    void CleanPlane();
};

#endif // MAINWINDOW_H
