#include "utils.h"

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