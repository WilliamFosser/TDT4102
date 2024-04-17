#pragma once
#include <stdexcept>
#include <iostream>
#include <sstream>

template<typename Type, int Size>
class MyArray {
private: 

    Type elements[Size]; 

public: 

    static constexpr int getSize() {
        return Size;
        //return sizeof(elements) / sizeof(Type);
    }

    Type& at(unsigned long index) {
        if (index < 0 || index >= getSize()){
            throw std::out_of_range("index out of the arrays range");
        }
        return elements[index];
    } 

    void fill(Type instance) {
        for (int i = 0; i < Size; i++) {
            elements[i] = instance;
        }
    }

};

void testMyArray(); 

template<typename Type, int Size>
void printMyArray(MyArray<Type, Size>& ma) {
    std::ostringstream outStream;
    outStream << "(";
    for (int i = 0; i < ma.getSize(); i++) {
        outStream << ma.at(i);
        if (i != ma.getSize() - 1) {
        outStream << ", ";
        } 
    }
    outStream << ")";
    std::cout << outStream.str() << std::endl;
}
