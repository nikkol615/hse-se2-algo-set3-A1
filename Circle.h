#pragma once

class Circle {
public:
    double radius;
    double x;
    double y;
    Circle(double x, double y, double r);
    bool isPointInside(double px, double py);
};
