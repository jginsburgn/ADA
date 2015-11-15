#include "painter.h"

float dtr(float degrees) {
    return (degrees*PI/180);
}//Degrees to radians

Painter::Painter()
{
    outlinePen = QPen(Qt::black);
    outlinePen.setWidth(1);
}

void Painter::DrawFigure(Figure & newFigure, QGraphicsScene * newScene){
    figure = newFigure;
    scene = newScene;
    
    if (scene != nullptr)
    for (int i = 1; i < figure.DrawPathSize(); ++i) {
        std::pair<float, float> firstPoint = figure.GetPointAt(i - 1);
        std::pair<float, float> secondPoint = figure.GetPointAt(i);
        newScene->addLine(firstPoint.first, firstPoint.second,
                       secondPoint.first, secondPoint.second,
                       outlinePen);
    }
    
}

void Painter::RotateFigure(const float & degrees) {
    if (figure.DrawPathSize() != 0) {
        Figure newFigure;
        for (int i = 0; i < figure.DrawPathSize(); ++i) {
            std::pair<float, float> oldPoint = figure.GetPointAt(i);
            std::pair<float, float> newPoint;
            newPoint.first = oldPoint.first*cos(dtr(degrees))-oldPoint.second*sin(dtr(degrees));
            newPoint.second = oldPoint.first*sin(dtr(degrees))+oldPoint.second*cos(dtr(degrees));
            newFigure.AddDrawingPoint(newPoint);
        }
        figure = newFigure;
        DrawFigure(figure, scene);
    }
}

void Painter::XTranslateFigure(const float & amount) {
    if (figure.DrawPathSize() != 0) {
        Figure newFigure;
        for (int i = 0; i < figure.DrawPathSize(); ++i) {
            std::pair<float, float> oldPoint = figure.GetPointAt(i);
            std::pair<float, float> newPoint;
            newPoint.first = oldPoint.first + amount;
            newPoint.second = oldPoint.second;
            newFigure.AddDrawingPoint(newPoint);
        }
        figure = newFigure;
        DrawFigure(figure, scene);
    }
}

void Painter::YTranslateFigure(const float & amount) {
    if (figure.DrawPathSize() != 0) {
        Figure newFigure;
        for (int i = 0; i < figure.DrawPathSize(); ++i) {
            std::pair<float, float> oldPoint = figure.GetPointAt(i);
            std::pair<float, float> newPoint;
            newPoint.first = oldPoint.first;
            newPoint.second = oldPoint.second + amount;
            newFigure.AddDrawingPoint(newPoint);
        }
        figure = newFigure;
        DrawFigure(figure, scene);
    }
}

void Painter::XReflectFigure() {
    if (figure.DrawPathSize() != 0) {
        Figure newFigure;
        for (int i = 0; i < figure.DrawPathSize(); ++i) {
            std::pair<float, float> oldPoint = figure.GetPointAt(i);
            std::pair<float, float> newPoint;
            newPoint.first = oldPoint.first;
            newPoint.second = -oldPoint.second;
            newFigure.AddDrawingPoint(newPoint);
        }
        figure = newFigure;
        DrawFigure(figure, scene);
    }
}

void Painter::YReflectFigure() {
    if (figure.DrawPathSize() != 0) {
        Figure newFigure;
        for (int i = 0; i < figure.DrawPathSize(); ++i) {
            std::pair<float, float> oldPoint = figure.GetPointAt(i);
            std::pair<float, float> newPoint;
            newPoint.first = -oldPoint.first;
            newPoint.second = oldPoint.second;
            newFigure.AddDrawingPoint(newPoint);
        }
        figure = newFigure;
        DrawFigure(figure, scene);
    }
}

void Painter::XScaleFigure(const float & scaleFactor) {
    if (figure.DrawPathSize() != 0) {
        Figure newFigure;
        for (int i = 0; i < figure.DrawPathSize(); ++i) {
            std::pair<float, float> oldPoint = figure.GetPointAt(i);
            std::pair<float, float> newPoint;
            newPoint.first = oldPoint.first*scaleFactor;
            newPoint.second = oldPoint.second;
            newFigure.AddDrawingPoint(newPoint);
        }
        figure = newFigure;
        DrawFigure(figure, scene);
    }
}

void Painter::YScaleFigure(const float & scaleFactor) {
    if (figure.DrawPathSize() != 0) {
        Figure newFigure;
        for (int i = 0; i < figure.DrawPathSize(); ++i) {
            std::pair<float, float> oldPoint = figure.GetPointAt(i);
            std::pair<float, float> newPoint;
            newPoint.first = oldPoint.first;
            newPoint.second = oldPoint.second*scaleFactor;
            newFigure.AddDrawingPoint(newPoint);
        }
        figure = newFigure;
        DrawFigure(figure, scene);
    }
}

Figure Painter::GetCurrentFigure() const {
    return figure;
}