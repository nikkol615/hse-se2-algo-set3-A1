#pragma once

#include <iostream>
#include "Circle.h"
#include <random>
#include <utility>
#include <vector>

struct MonteCraloParams {
    int start;
    int end;
    int step;
};

struct Point {
    double x;
    double y;
};

struct SquareParams {
    double x;
    double y;
    double width;
    double height;
};

Point getRandomPoint(SquareParams square);
std::vector<std::pair<double, int>> circleIntersectionArea(Circle c1, Circle c2, Circle c3, MonteCraloParams params, SquareParams square);
double mostLeftPoint(Circle c1, Circle c2, Circle c3);
double mostRightPoint(Circle c1, Circle c2, Circle c3);
double mostTopPoint(Circle c1, Circle c2, Circle c3);
double mostBottomPoint(Circle c1, Circle c2, Circle c3);