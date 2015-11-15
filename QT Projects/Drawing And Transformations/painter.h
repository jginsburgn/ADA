#ifndef PAINTER_H
#define PAINTER_H

#include <QDebug>
#include <QGraphicsScene>
#include "figure.h"

class Painter{

private:

    QGraphicsScene * scene;
    Figure figure;
    QPen outlinePen;

public:
    Painter();

    void DrawFigure(Figure & newFigure, QGraphicsScene * newScene);
    void RotateFigure(const float & degrees);
    void XTranslateFigure(const float & amount);
    void YTranslateFigure(const float & amount);
    void XReflectFigure();
    void YReflectFigure();
    void XScaleFigure(const float & scaleFactor);
    void YScaleFigure(const float & scaleFactor);
    
    Figure GetCurrentFigure() const;
};

#endif // PAINTER_H
