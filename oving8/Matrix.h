#pragma once
#include <iostream>

class Matrix {
public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);


    ~Matrix(); 
    

private: 
    int rows; 
    int cols;
    int** matrix;
};

