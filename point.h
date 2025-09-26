#ifndef POINT_H
#define POINT_H

class Point {
    double x, y;
public:
    Point(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void set(double xVal, double yVal) { x = xVal; y = yVal; }
    double distance(const Point &other) const;
};

#endif
