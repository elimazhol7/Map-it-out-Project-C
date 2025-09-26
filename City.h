#ifndef CITY_H
#define CITY_H

#include "Point.h"
#include <cstring>
#include <iostream>
using namespace std;

const size_t MAX_CITY_NAME = 50;

class City {
    Point location;
    char name[MAX_CITY_NAME];
public:
    City() { strcpy(name, ""); }
    City(const char* cityName, double x, double y) {
        strncpy(name, cityName, MAX_CITY_NAME - 1);
        name[MAX_CITY_NAME - 1] = '\0';
        location.set(x, y);
    }
    double distance(const City &other) const {
        return location.distance(other.location);
    }
    Point get_location() const { return location; }
    const char* get_name() const { return name; }
    void set(const char* cityName, double x, double y) {
        strncpy(name, cityName, MAX_CITY_NAME - 1);
        name[MAX_CITY_NAME - 1] = '\0';
        location.set(x, y);
    }
    void print() const {
        cout << name << " (" << location.getX() << ", " << location.getY() << ")";
    }
};

#endif
