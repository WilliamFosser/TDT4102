#pragma once
#include <iostream>
#include <random>
#include <iostream>

// For å fungere på egne objekter kreves det en operatoroverlastning av > operatoren for objektet.
template<typename T>
T maximum(T number1, T number2) {
    if (number1 > number2) {
        return number1; 
    }
    return number2; 
}

void templateTestMaximum();


template<typename T>
void shuffle(std::vector<T>& v) {
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> uniform_dist(0, v.size()-1);
    
    for (int i = 0; i < 2*v.size(); i++) {
        int randomNumber1 = uniform_dist(engine);
        int randomNumber2 = uniform_dist(engine);
        std::swap(v.at(randomNumber1), v.at(randomNumber2)); 
    }
}

#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& outStream, std::vector<T>& vector) {
    outStream << "(";
    for (T element : vector) {
        outStream<< element; 
        if (element != vector.back()) {
            outStream << ", ";
        }
    }
    outStream << ")";
    return outStream; 
}

void templateTestShuffle(); 
