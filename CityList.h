#ifndef CITYLIST_H
#define CITYLIST_H

#include "City.h"

const int MAX_CITIES = 10;

class CityList {
    City cities[MAX_CITIES];
    int count;
public:
    CityList() : count(0) {}

    int getCount() const { return count; }
    bool isFull() const { return count >= MAX_CITIES; }
    void addCity(const City &c);
    void overwriteCity(int index, const City &c);
    void printAll() const;
    const City& getCity(int index) const;
};

#endif
