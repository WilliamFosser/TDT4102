#include "MyArray.h"
#include "templates.h"

enum class Cars {BMW, Volvo};

void testMyArray() {
    MyArray<int, 100> a1;
    MyArray<std::string, 5> a2;
    MyArray<Cars, 8> a3;

    a1.fill(8); 
    a2.fill("Hei");
    a3.fill(Cars::BMW);

    std::cout << "MyArray test: " << std::endl;
    printMyArray(a1); 
    printMyArray(a2); 
} 

