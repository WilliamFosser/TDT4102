#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int nRows, int nColumns) {
        matrix = new int*[nRows];
        for (int i = 0; i < nRows; i++) {
            matrix[i] = new int[nColumns];
        }
}

Matrix::Matrix(int nRows) {
    // constructor implementation
}

Matrix::~Matrix() {
    // destructor implementation
}
