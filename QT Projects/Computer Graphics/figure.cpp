#include "figure.h"

Figure::Figure()
{
    //No special initialization needed
}

void Figure::SetDrawPath(const std::vector<std::pair<float, float>> & newDrawPath){
    drawPath = newDrawPath;
}

int Figure::DrawPathSize() const {
    return (int)drawPath.size();
}

std::vector<std::pair<float, float>> Figure::GetDrawPath() const{
    return drawPath;
}

std::pair<float, float> Figure::GetPointAt(const int & position) const{
    return drawPath.at(position);
}

void Figure::AddDrawingPoint(const std::pair<float, float> & newPoint){
    drawPath.push_back(newPoint);
}


void Figure::RemoveDrawingPoint(const int & at){
    drawPath.erase(drawPath.begin() + at);
}


void Figure::RemoveDrawingPoint(const std::pair<float, float> & point){
    for (int i = 0; i < (int)drawPath.size(); ++i){
        if (drawPath.at(i) == point) {
            RemoveDrawingPoint(i);
            return;
        }
    }
}

