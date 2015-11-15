#ifndef FIGURE_H
#define FIGURE_H

#include <QDebug>
#include <math.h>
#include <vector>
#include <utility>
#include <iostream>

#define PI 3.14159265

class Figure {

private:
    std::vector<std::pair<float, float>> drawPath;

public:
    Figure();

    static Figure BuildPolygon(const int & sides) {
        Figure retVal;
        //Declare reference radius
        const float radius = 100;

        //Create first point
        std::pair<float, float> firstPoint(radius, 0);
        retVal.AddDrawingPoint(firstPoint);

        //Create all other points (repeating first for connection of lines)
        for (int i = 0; i < sides; ++i) {
            float xCoordinate = radius*cos((i+1)*2*PI/sides);
            float yCoordinate = radius*sin((i+1)*2*PI/sides);
            std::pair<float, float> newPoint(xCoordinate, yCoordinate);
            retVal.AddDrawingPoint(newPoint);
        }        
        return retVal;
    }

    static Figure BuildArc(const float & degrees) {
        Figure retVal;
        
        //Declare fineness
        const int fineness = 200;
        //Declare reference radius
        const float radius = 100;
        int sides = degrees*fineness/360;
        
        //Create first point
        std::pair<float, float> firstPoint(radius, 0);
        retVal.AddDrawingPoint(firstPoint);
        
        //Create all other points (repeating first for connection of lines)
        for (int i = 0; i < sides; ++i) {
            float xCoordinate = radius*cos((i+1)*2*PI/fineness);
            float yCoordinate = radius*sin((i+1)*2*PI/fineness);
            std::pair<float, float> newPoint(xCoordinate, yCoordinate);
            retVal.AddDrawingPoint(newPoint);
        }
        return retVal;
    }
    
    static Figure BuildCube(){
        Figure retVal;
        
        const float genericSize = 50;
        const float half = genericSize/2;
        
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, -genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(-genericSize, -genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(-genericSize, genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize + half, genericSize + half));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize + half, -genericSize + half));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, -genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(-genericSize, genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(-genericSize + half, genericSize + half));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize + half, genericSize + half));
        
        return retVal;
    }
    
    static Figure BuildRectangularPrism(){
        Figure retVal;
        
        const float genericSize = 50;
        const float half = genericSize/2;
        
        
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, -half));
        retVal.AddDrawingPoint(std::pair<float, float>(-genericSize, -half));
        retVal.AddDrawingPoint(std::pair<float, float>(-half, 0));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize + half, 0));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, -half));
        retVal.AddDrawingPoint(std::pair<float, float>(0, 2 * genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(-genericSize, -half));
        retVal.AddDrawingPoint(std::pair<float, float>(-half, 0));
        retVal.AddDrawingPoint(std::pair<float, float>(0, 2 * genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize + half, 0));
        
        return retVal;
    }
    
    static Figure BuildTriangularPrism(){
        Figure retVal;
        
        const float genericSize = 50;
        const float half = genericSize/2;
        
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, 0));
        retVal.AddDrawingPoint(std::pair<float, float>(-genericSize, 0));
        retVal.AddDrawingPoint(std::pair<float, float>(-half, half));
        retVal.AddDrawingPoint(std::pair<float, float>(genericSize, 0));
        retVal.AddDrawingPoint(std::pair<float, float>(0, 2 * genericSize));
        retVal.AddDrawingPoint(std::pair<float, float>(-half, half));
        retVal.AddDrawingPoint(std::pair<float, float>(-genericSize, 0));
        retVal.AddDrawingPoint(std::pair<float, float>(0, 2 * genericSize));
        
        return retVal;
    }
    
    static Figure BuildCone(){
        Figure retVal;
        Figure arc = Figure::BuildArc(360);
        
        const float height = 200;
        
        for (int i = 0; i < arc.DrawPathSize(); ++i) {
            std::pair<float, float> oldPoint = arc.GetPointAt(i);
            std::pair<float, float> newPoint;
            newPoint.first = oldPoint.first;
            newPoint.second = oldPoint.second * 0.2;
            retVal.AddDrawingPoint(newPoint);
        }
        
        retVal.AddDrawingPoint(std::pair<float, float>(0, height));
        retVal.AddDrawingPoint(std::pair<float, float>(-100, 0));
        
        return retVal;
    }
    

    void SetDrawPath(const std::vector<std::pair<float, float>> & newDrawPath);
    int DrawPathSize() const;
    std::vector<std::pair<float, float>> GetDrawPath() const;
    std::pair<float, float> GetPointAt(const int & position) const;

    void AddDrawingPoint(const std::pair<float, float> & newPoint);
    void RemoveDrawingPoint(const int & at);
    void RemoveDrawingPoint(const std::pair<float, float> & point);
};

#endif // FIGURE_H
