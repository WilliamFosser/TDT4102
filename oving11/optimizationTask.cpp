#include "Stopwatch.h"
#include <vector>
#include <iostream>

/*
Globale endringer: 
1. Byttet ut datatypen double med float der ekstra presisjon ikke er nødvendig. 
2. Begrenset til en for-loop da det ikke er nødvendig å loope gjennom alle ellementene 
   i collonnevektoren i en kvadratisk matrise for å finne diagonalen. 
3. Bruker [] og ikke .at() da det gir litt bedre ytelse. 
*/
void setDiagonalValue(std::vector<std::vector<float>>& matrix, const float& newValue, const int& matrixSize){
    for (int i = 0; i < matrixSize; i++){ 
        // fjernet unødvendig if-test for col==row. Trengs ikke å evalueres da (index, index) gir koordinatetene til diagonalen
        matrix[i][i] = newValue;
    } 
}

double sumMatrix(const std::vector<std::vector<float>>& matrix, const int& matrixSize){
    double sum;

    for (int i = 0; i < matrixSize*matrixSize; i++) {
        sum += matrix[static_cast<int>(i/matrixSize)][i-matrixSize*static_cast<int>(i/matrixSize)];
    }


    /*
    for (int row = 0; row < matrix.size(); row++){
        for (int col = 0; col < matrix.size(); col++) {
            sum += matrix[row][col];
        }
                   
    }

    */
    return sum;
}

void optimizationTask() {
    
    constexpr int matrixSize = 10000;

    // Create a matrix with zeros
     // Allokerer nok minne med en gang. 
    std::vector<std::vector<float>> matrix(matrixSize, std::vector<float>(matrixSize, 0.0f));
  
   // Kvitter med meg hele for løkka, og allokerer minne og fyller vektoren med nuller. 

    // Set all elements on the diagonal to 0.41
    constexpr float diagonalValue = 0.41;
    setDiagonalValue(matrix, diagonalValue, matrixSize);

    // Sum all elements in the matrix
    double total = sumMatrix(matrix, matrixSize);
    double coolerNumber = total + 2;
    std::cout << "TDT" << coolerNumber << std::endl;
}