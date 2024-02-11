#include "std_lib_facilities.h"
#include "test.h"
#include "utilities.h"
#include "mastermind.h"
#

void testMenu() {
    while (true) {
    cout << "Velg funksjon for testing:\n"
         << "0)\tAvslutt\n"
         << "1)\tTester funksjonen: testCallByValue()\n";

        int menuChoice;
        cin >> menuChoice;
        cout << "\n";

        switch (menuChoice) {
        case 1:
            testCallByValue();
            break;
        case 2: 
            testCallByReference();
            break;
        case 3:
            testString();
            break; 
        case 4: 
            if (countChar("Hei Hei Hei", 'H') == 3) {
                cout << "Test vellykket!" << endl;
            }
            break; 
        case 5:
            cout << "Antall riktige bokstaver og posisjoner: " << checkCharactersAndPosition("ABC", "CBA") << endl;
            break;
        case 6:
            cout << "Resulatat: " << checkCharacters("ABC", "CBA") << endl;
            break;
        case 7:
            playMastermind();
            break;
        
        default: 
            return;
            
        }
        cout << "\n";
    }
}

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << " result: " << v0 << endl;
}

void testString() {
    string grades = randomizeString(8, 'A', 'F'); 
    cout << "Karakterer: " << grades << endl;

    vector<int> gradeCount(6, 0);
    array<char, 6> possibleGrades = {'A', 'B', 'C', 'D', 'E', 'F'};

    for (char grade : grades) {
        for (int i = 0; i < possibleGrades.size(); i++) {
            if (grade == possibleGrades.at(i)) {
                gradeCount.at(i)++;
                break;
            }
        }
    }

    cout << "Antall av hver karakter: " << endl;
    for (int i = 0; i < gradeCount.size(); i++) {
        cout << possibleGrades.at(i) << ":\t" << gradeCount.at(i) << endl;
    }

    double counter = 0.0;
    double multiplyer = 5.0;
    for (int i = 0; i < gradeCount.size(); i++) {
        counter += (gradeCount.at(i) * multiplyer);
        multiplyer--;    }
    double meanGrade = counter/8.0; 
    cout << "Gjennomsnittskarakteren er: " << setprecision(2) << fixed << meanGrade << endl;
}
