#include "Point.h"
#include <cmath>

double Point::distance(const Point &other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx*dx + dy*dy);
}
