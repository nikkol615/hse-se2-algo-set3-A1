#include "utils.h"
#include <fstream>
#include <cmath>
#define PI 3.14159265358979323846
// This code was used for get results.csv file

int main() {
    Circle c1(1, 1, 1);
    Circle c2(1.5, 2, sqrt(5)/2);
    Circle c3(2, 1.5, sqrt(5)/2);
    double realArea = PI * 0.25 + 1.25 * asin(0.8) - 1;
    std::cout << "Real area: " << realArea << std::endl;
    MonteCraloParams params = {.start = 100, .end = 100000, .step = 500};
    SquareParams square = {.x = 0, .y = 0, .width = 2 + sqrt(5)/2, .height = 2 + sqrt(5)/2};
    std::vector<std::pair<double, int>> result = circleIntersectionArea(c1, c2, c3, params, square);
    for (const auto& pair : result) {
        double error = pair.first - realArea;
        std::cout << pair.second << "," << pair.first << "," << error << std::endl;
    }
}