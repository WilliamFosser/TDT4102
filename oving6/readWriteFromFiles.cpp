#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "readWriteFromFiles.h"


void saveInputWordsInFile() {
    std::string inputWord; 
    std::string inputWords;
    do {
    std::cin >> inputWord;
    if (inputWord == "quit") {
        break;
    }
    inputWords += inputWord + " ";
    std::cout << inputWords << std::endl;
    } while (true);
    std::filesystem::path fileNameToWriteString{"stringFile.txt"};
    std::ofstream writeStream{fileNameToWriteString};
    std::istringstream iss(inputWords);
    std::string word;
    while (iss >> word) {
        writeStream << word << std::endl;
    }
    writeStream.close();
}


void addLineNumbersAndWriteNewFile(std::filesystem::path readFileName) {
    std::filesystem::path writeFileName{"FileWithAddedLineNumbers.txt"};
    std::ifstream inputStream(readFileName);
    if (inputStream.is_open()) {  // Spørre om .is_open() vs !inputStrem
        std::string line; 
        int lineNumber = 1;
        std::ofstream outputStream{writeFileName};
        while (getline(inputStream, line)) {
            outputStream << lineNumber << ". " << line << std::endl;
            lineNumber++;
        }
        inputStream.close();
    }
    else {
        std::cout << "Kunne ikke åpne filen" << std::endl;
    }
}


// Oppgave 2a)
// Kodelinjen "return capitalsMap.[country];" forårsaker problemet. Problemet oppstår forde 
// det er en const map, og operatoren [] potensielt har mulighet til å endre map-et.


