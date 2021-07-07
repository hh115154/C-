#pragma once
#include <string>
#include <vector>
class Point
{
public:
    double x;
    double y;
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

class PolygonAlgorithm
{
public:
    static string rayCasting(Point p, vector<Point> poly);
};