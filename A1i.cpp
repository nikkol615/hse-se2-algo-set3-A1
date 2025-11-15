#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <utility>
// This code is solution of A1i in Codeforces 

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

class Circle {
public:
    double radius;
    double x;
    double y;
    Circle(double x, double y, double r);
    bool isPointInside(double px, double py);
};

Circle::Circle(double x, double y, double r) {
    this->radius = r;
    this->x = x;
    this->y = y;
}

bool Circle::isPointInside(double px, double py) {
    return (px - x) * (px - x) + (py - y) * (py - y) <= radius * radius;
}

Point getRandomPoint(SquareParams square) {
    return {.x = square.x + rand() / (double)RAND_MAX * square.width, .y = square.y + rand() / (double)RAND_MAX * square.height};
}

double mostLeftPoint(Circle c1, Circle c2, Circle c3) {
    return std::min(c1.x - c1.radius, std::min(c2.x - c2.radius, c3.x - c3.radius));
}

double mostRightPoint(Circle c1, Circle c2, Circle c3) {
    return std::max(c1.x + c1.radius, std::max(c2.x + c2.radius, c3.x + c3.radius));
}

double mostTopPoint(Circle c1, Circle c2, Circle c3) {
    return std::max(c1.y + c1.radius, std::max(c2.y + c2.radius, c3.y + c3.radius));
}

double mostBottomPoint(Circle c1, Circle c2, Circle c3) {
    return std::min(c1.y - c1.radius, std::min(c2.y - c2.radius, c3.y - c3.radius));
}

std::vector<std::pair<double, int>> circleIntersectionArea(Circle c1, Circle c2, Circle c3, MonteCraloParams params, SquareParams square) {
    int totalPoints = 0;
    int pointsInside = 0;
    std::vector<std::pair<double, int>> result;
    double area = square.width * square.height;
    for (int i = params.start; i <= params.end; i += params.step) {
        int newPoints = i - totalPoints;
        for (int j = 0; j < newPoints; j++) {
            Point point = getRandomPoint(square);
            if (c1.isPointInside(point.x, point.y) && c2.isPointInside(point.x, point.y) && c3.isPointInside(point.x, point.y)) {
                pointsInside++;
            }
        }
        totalPoints = i;
        result.push_back(std::make_pair(pointsInside / (double)totalPoints * area, i));
    }
    return result;
}

int main() {
    double x1, y1, r1, x2, y2, r2, x3, y3, r3;
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 >> x3 >> y3 >> r3;
    Circle c1(x1, y1, r1);
    Circle c2(x2, y2, r2);
    Circle c3(x3, y3, r3);
    double mostLeft = mostLeftPoint(c1, c2, c3);
    double mostRight = mostRightPoint(c1, c2, c3);
    double mostTop = mostTopPoint(c1, c2, c3);
    double mostBottom = mostBottomPoint(c1, c2, c3);
    SquareParams square = {.x = mostLeft, .y = mostBottom, .width = mostRight - mostLeft, .height = mostTop - mostBottom};
    MonteCraloParams params = {.start = 100, .end = 1000000, .step = 1000};
    std::vector<std::pair<double, int>> result = circleIntersectionArea(c1, c2, c3, params, square);
    double ans = result.back().first;
    std::cout << ans << std::endl;
}