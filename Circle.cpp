#include "Circle.h"

Circle::Circle(double x, double y, double r) {
    this->radius = r;
    this->x = x;
    this->y = y;
}

bool Circle::isPointInside(double px, double py) {
    return (px - x) * (px - x) + (py - y) * (py - y) <= radius * radius;
}