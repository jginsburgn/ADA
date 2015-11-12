#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>

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
    void on_runButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

protected:
    void mousePressEvent(QMouseEvent * event);

};

#endif // MAINWINDOW_H
