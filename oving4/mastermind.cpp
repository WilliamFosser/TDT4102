#include "mastermind.h"
#include "utilities.h"
#include "test.h"
#include "std_lib_facilities.h"

void playMastermind() {
    constexpr int stringSize = 4; 
    constexpr int letterCount = 6; 
    // Bruker constexpr for at konstantene skal evalueres ved kompileringstid, og dermed optimalisere koden.
    // Hvis brukeren kunne valgt i starten av spillet ville const vært hensiktsmessig. 

    string code = randomizeString(stringSize, 'A', 'A' + (letterCount-1));
    string guess; 
    int maxGuesses = 6;

    int rightCharAndPosition = 0;
    int i = 0;
    
    do {
        cout << "Gjett en kode med " << stringSize << " bokstaver. Bokstavene skal være i intervallet A - " << char('A' + letterCount - 1) << endl;
        guess = readInputToString(stringSize, 'A', 'A' + (letterCount-1)); 
        rightCharAndPosition = checkCharactersAndPosition(code, guess);
        int rightChar = checkCharacters(code, guess);
        cout << "\nAntall riktige bokstaver på riktig plass: " << rightCharAndPosition << endl;
        cout << "Antall riktige bokstaver: " << rightChar << endl;
        cout << "Antall forsøk igjen: " << maxGuesses - i - 1 << endl << endl;
        i++;
    } while (rightCharAndPosition < stringSize && i < maxGuesses);
    if (rightCharAndPosition == stringSize) {
        cout << "Gratulerer! Du klarte det!" << endl;
    } else {
        cout << "Beklager, du tapte. Trykk 6 for å starte igjen" << code << endl;
    }
}

int checkCharactersAndPosition(string code, string guess) {
    int rightChar = 0;
    for (int i = 0; i < code.size(); i++) {
        rightChar += code.at(i) == guess.at(i);
    }
    return rightChar;
}


int checkCharacters(string code, string guess) {
    int rightChar = 0;
    for (char c = 'A'; c <= 'F'; c++) {
        int countInCode = countChar(code, c);
        int countInGuess = countChar(guess, c);
        rightChar += min(countInCode, countInGuess);
    }
    return rightChar;
}

