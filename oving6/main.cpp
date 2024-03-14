#include "readWriteFromFiles.h"
#include "courseCatalog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "bouncingBall.h"

int main() {
    int menuChoice;
    std::cout << "Velg en funkjson å tese" << std::endl;
    std::cout << "1: saveInputWordsInFile and addLineNumbersAndWriteNewFile" << std::endl;
    std::cout << "2: testCourseCatalogAnOverlad" << std::endl;
    std::cout << "3: bouncingBall" << std::endl;
    std::cin >> menuChoice;
    std::filesystem::path fileToRead{"stringFile.txt"};
    
        switch (menuChoice) {
            case 1: 
                saveInputWordsInFile();
                
                addLineNumbersAndWriteNewFile(fileToRead);
                break;
            case 2: 
                testCourseCatalogAnOverlad();
                break;
            case 3: 
                bouncingBall();
                break;
            default: 
                std::cout << "Ugyldig valg" << std::endl;
                break;
        }
        
    return 0;
    
} 

   

