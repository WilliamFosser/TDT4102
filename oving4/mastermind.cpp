#include "masterMind.h"
#include "utilities.h"
#include "std_lib_facilities.h"

void playMastermind() {
    constexpr int stringSize = 4; 
    constexpr int letterCount = 6; 
    // Bruker constexpr for at konstantene skal evalueres ved kompileringstid, og dermed optimalisere koden.
    // Hvis brukeren kunne valgt i starten av spillet ville const vært hensiktsmessig. 

    string code = randomizeString(stringSize, 'A', 'A' + (letterCount-1));
    string guess = readInputToString(stringSize, 'A', 'A' + (letterCount-1));
}

int checkCharactersAndPosition(string code, string guess) {
    int rightChar = 0; 
    for (int i = 0; i < stringSize; i++) {
        if (coda.at(i) == guess.at(i)) {
            rightChar++;
        }
    }
    return rightChar; 
}

int checkCharacters(string code, string guess) {
    int rightChar = 0; 
    for (int i = 0; i < stringSize; i++) {
        char check = code.at(i)
        for (int j = 0; j < stringSize; j++) {
            if (check == guess.at(i)) {
                rightChar++;
                break;
            }
        }
    }
}