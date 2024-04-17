#include "templates.h"

void templateTestMaximum() {
    int a = 1;
    int b = 2;
    int c = maximum<int>(a, b);
    // c er nå 2.

    double d = 2.4;
    double e = 3.2;
    double f = maximum<double>(d,e);
    // f er nå 3.2

    if (c == 2 && f == 3.2) {
        std::cout << "Test av templatefunksjonen maximum() vellykket" << std::endl; 
    }
}


void templateTestShuffle() {
    std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
    shuffle(a); // Resultat, rekkefølgen i a er endret.
    std::vector<double> b{1.2, 2.2, 3.2, 4.2};
    shuffle(b); // Resultat, rekkefølgen i b er endret.
    std::vector<std::string> c{"one", "two", "three", "four"};
    shuffle(c); // Resultat, rekkefølgen i c er endret.

    std::cout << "Vektorene stokket i tilfeldig rekkefølge: " << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}


