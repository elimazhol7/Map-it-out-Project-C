#include "CityList.h"
#include <iostream>
using namespace std;

void CityList::addCity(const City &c) {
    if (!isFull()) {
        cities[count++] = c;
    }
}

void CityList::overwriteCity(int index, const City &c) {
    if (index >= 0 && index < count) {
        cities[index] = c;
    }
}

void CityList::printAll() const {
    for (int i = 0; i < count; i++) {
        cout << i+1 << ") ";
        cities[i].print();
        cout << endl;
    }
}

const City& CityList::getCity(int index) const {
    return cities[index];
}
