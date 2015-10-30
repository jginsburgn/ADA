//
//  main.cpp
//  2DFigureTransformation
//
//  Created by Jonathan Ginsburg on 10/29/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <math.h>

#include "../../Helper.h"
struct point {
    float x;
    float y;
};
point origin = {0, 0};

void printPoint(point p){
    std::cout << "(" << p.x << ", " << p.y << ")";
}

void printFigure(std::vector<point> & figure){
    for (int i = 0; i < figure.size(); ++i) {
        printPoint(figure[i]);
    }
}

void scale(float xfactor, float yfactor, std::vector<point> & figure){
    for (int i = 0; i < figure.size(); ++i) {
        point oldPoint = figure[i];
        figure[i] = {(float)(oldPoint.x * xfactor), (float)(oldPoint.y * yfactor)};
    }
}

void translate(point delta, std::vector<point> & figure){
    for (int i = 0; i < figure.size(); ++i) {
        point oldPoint = figure[i];
        figure[i] = {(float)(oldPoint.x + delta.x), (float)(oldPoint.y + delta.y)};
    }
}

void figRotate(float angle, point pivot, std::vector<point> & figure){
    angle = angle*M_PI/180;
    point minusPivot = {-pivot.x, -pivot.y};
    translate(minusPivot, figure);
    for (int i = 0; i < figure.size(); ++i) {
        point oldPoint = figure[i];
        point newPoint = {(float)(oldPoint.x * cos(angle) - oldPoint.y * sin(angle)), (float)(oldPoint.x * sin(angle) + oldPoint.y * cos(angle))};
        figure[i] = newPoint;
    }
    translate(pivot, figure);
}

int main(int argc, const char * argv[]) {
    std::vector<point> figure;
    figure.push_back({1, 1});
    figure.push_back({1, 2});
    figure.push_back({2, 1});
    figure.push_back({2, 2});
    printFigure(figure);
    figRotate(45, {1.5, 1.5}, figure);
    std::cout << std::endl;
    printFigure(figure);
    return 0;
}
