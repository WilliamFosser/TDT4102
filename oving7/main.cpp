#include "std_lib_facilities.h"

const map<string, string> capitalsMap {
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}
    };


string getCapital(const string& country) {
    return capitalsMap.at(country);
}


int main() {
    cout << "Capitals:" << endl;
    for (pair<const string, const string> elem : capitalsMap) {
    cout << getCapital(elem.first) << endl;
    }
    return 0;
}