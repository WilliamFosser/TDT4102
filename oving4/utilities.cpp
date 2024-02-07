#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
    startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, const int& increment, const int& numTimes) {
    for (int i = 0; i < numTimes; i++) {
    startValue += increment;
    }
}

// Funksjonen bør bruke pass-by-referance fordi vi ønsker å endre på verdiene til a og b globalt. 
void swapNumbers(int& a, int& b) {
    int temp_a = a;
    a = b;
    b = temp_a;
}

void printStudent(Student student) {
    cout << "Name:\t" << student.name << "\n"
         << "Study program:\t" << student.studyProgram << "\n"
         << "Age:\t" << student.age << "\n";
}

bool isInProgram(Student student, string studyProgram) {
    return student.studyProgram == studyProgram;
}

// implementerte random number generator som generell funksjon.
int randomWithLimits(int lowerLimit, int upperLimit) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(lowerLimit, upperLimit);

    int randomNumber = distribution(generator);
    return randomNumber;    
}

string randomizeString(int stringLength, char lowerInInterval, char upperInInterval) {
    string randomString; 
    for (int i = 0; i < stringLength; i++) {
        randomString += toupper(static_cast<char>(randomWithLimits(lowerInInterval, upperInInterval)));
    }
    return randomString;
}

string readInputToString(int stringLength, char lowerCharLimit, char upperCharLimit) {
    string readInString; 
    while (readInString.size() < stringLength) {
        cout << "Skriv inn en bokstav: "; 
        char inputChar; 
        cin >> inputChar;
        if (inputChar >= static_cast<int>(lowerCharLimit) 
            && inputChar <= static_cast<int>(upperCharLimit)) {
                readInString += toupper(inputChar);
        } else {
                cout << "Bokstaven er ikke gyldig. Prøv igjen: " << endl; 
        }
    }
    return readInString;
}

int countChar(string strToCheck, char charToCount) {
    int charCount = 0; 
    for (const char& character : strToCheck) {
        if (character == charToCount) {
            charCount++;
        }
    }
    return charCount; 
}

