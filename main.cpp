#include <iostream>
#include <cctype>
#include "CityList.h"
using namespace std;

char menu() {
    cout << "\nMenu:\n"
         << "1) Enter city Information\n"
         << "2) Calculate Distance between two cities\n"
         << "3) Print All cities\n"
         << "4) Quit\n";
    cout << "Choice: ";
    string choice;
    cin >> choice;
    return toupper(choice[0]);
}

int main() {
    CityList list;

    while (true) {
        char choice = menu();

        if (choice == '1') {
            if (list.isFull()) {
                cout << "List is full. Overwrite an existing city? (y/n): ";
                char ans; cin >> ans;
                if (tolower(ans) == 'y') {
                    list.printAll();
                    cout << "Enter city number to overwrite: ";
                    int index; cin >> index;
                    cin.ignore();
                    cout << "Enter city name: ";
                    string name; getline(cin, name);
                    double x, y;
                    cout << "Enter coordinates (x y): ";
                    cin >> x >> y;
                    list.overwriteCity(index-1, City(name.c_str(), x, y));
                }
            } else {
                cin.ignore();
                cout << "Enter city name: ";
                string name; getline(cin, name);
                double x, y;
                cout << "Enter coordinates (x y): ";
                cin >> x >> y;
                list.addCity(City(name.c_str(), x, y));
            }

        } else if (choice == '2') {
            if (list.getCount() < 2) {
                cout << "Need at least 2 cities.\n";
            } else if (list.getCount() == 2) {
                cout << "Distance = " << list.getCity(0).distance(list.getCity(1)) << endl;
            } else {
                list.printAll();
                int c1, c2;
                cout << "Pick first city: "; cin >> c1;
                cout << "Pick second city: "; cin >> c2;
                if (c1 == c2) cout << "Cannot pick same city!\n";
                else
                    cout << "Distance = " 
                         << list.getCity(c1-1).distance(list.getCity(c2-1)) << endl;
            }

        } else if (choice == '3') {
            list.printAll();

        } else if (choice == '4' || choice == 'Q') {
            cout << "Goodbye!\n";
            break;

        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
