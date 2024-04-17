#include "Stopwatch.h"
#include "optimizationTask.h"
#include "templates.h"
#include "MyArray.h"
#include <array>
#include <vector>



// a) Kapasiteten dobbles hver gang lengde overskrider kapasitet. 
void testVector() {
    std::vector<int> v; 
    for (int i = 0; i < 20; i++) {
        v.push_back(i); 
        std::cout << "Verdi: " << v.at(i) << "\t" << "Lengde: " << v.size() << "\t" << "Kapasitet: " << v.capacity() << std::endl; 
    }
}


// b) Kapasitet alltid lik 20. Samme vektor som i a) utern endringer i løkka. 
void testVecotorWithReserve() {
    std::vector<int> v; 
    v.reserve(20);
    for (int i = 0; i < 20; i++) {
        v.push_back(i); 
        std::cout << "Verdi: " << v.at(i) << "\t" << "Lengde: " << v.size() << "\t" << "Kapasitet: " << v.capacity() << std::endl; 
    }
}












int main() {

    Stopwatch timer;
    timer.start();
    for (int i = 0; i < 1000000; i++) {
    
    constexpr int size = 10000;

    // Stack allocation
    //std::array<int, size> arr1;

    //Heap allocation
    std::array<int, size>* arr2 = new std::array<int, size>;
    delete arr2;




    }
    double executionTime = (timer.stop()/1000000);

    std::cout << "Ytelsesmåling = " << executionTime << std::endl;

    testVector();
    std::cout << std::endl;
    testVecotorWithReserve();

    Stopwatch timer1; 
    timer1.start();
    std::vector<int> v;
    v.reserve(1000000); 
    for (int i = 0; i < 1000000; i++) {
        v.push_back(5);
    }
    double time = timer1.stop(); 

    std::cout << "Tid vektorallokering reserve(): " << time << std::endl;

////////////////////////////////////////
    Stopwatch timer2; 
    timer2.start();
    std::vector<int> v1;
    v1.resize(1000000); 
    for (int i = 0; i < 1000000; i++) {
        v.at(i) = 5;
        //std::cout << v.at(i) << std::endl;
    }
    double time1 = timer1.stop(); 

    std::cout << "Tid vektorallokering resize(): " << time1 << std::endl;

    Stopwatch optimizationTimer; 
    optimizationTimer.start(); 
    optimizationTask();
    double time2 = optimizationTimer.stop();

    std::cout << "Tid optimizationTask(): " << time2 << std::endl;

    templateTestMaximum();

    std::vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shuffle(vector);
    templateTestShuffle();
    testMyArray();
    return 1;
}

/*

Resultater:

Stack = 2.243e-09
Heap = 2.0935e-08 

Konklusjon: Heap ca. 1 størrelsesorden treigere

Uoptimalisert optimizationTask() = 7.51186s
Optimalisert optimizationTask() med kompilatoroptimalisering = 0.15s 



*/