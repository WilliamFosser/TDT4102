#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    double deviation = abs(compareOperand - toOperand);
    if (deviation <= maxError) {
        cout << "Avvik for " << name << " var: " << deviation << endl;
        cout << "Testen var vellykket!" << endl;
    }
    else {
        cout << "Avvik for " << name << "var: " << deviation << endl;
        cout << "Testen var mislykket!" << endl;
    }
}

void testMenu() {
    while (true) {
        cout    << "Velg funksjon for testing:\n"
                << "1: Test av kanonkulefunksjoner\n"
                << "2: Test av getVelocityVector\n"
                << "3: Test av getDistanceTraveled\n"
                << "4: Test av randomWithLimits\n"
                << "5: Test av playTargetPractice\n"
                << "6: Avslutt\n";
        
        int menuChoice;
        cin >> menuChoice;
        cout << "\n";
        vector velocityVector = makeVelocityVector(27.5, 15.64);
        
        switch (menuChoice) {
        case 1:
            testDeviation(posX(0.0,50.0,5.0), 250.0, 0.00001, "posX(0.0,50.0,5.0)");
            testDeviation(posY(0.0,50.0,5.0), 127.375, 0.00001, "posY(0.0,50.0,5.0)");
            testDeviation(velY(50.0,5.0), 0.95, 0.00001, "velY(50.0,5.0)");
            testDeviation(acclY(), -9.81, 0.00001, "acclY()");
            testDeviation(flightTime(50.0), 10.1936799185, 0.00001, "flightTime(50.0)");
            break;

        case 2:
            
            for (int element = 0; element < velocityVector.size(); element++) {
                cout << velocityVector.at(element) << endl;
            }
            break;
        
        case 3:
            testDeviation(getDistanceTraveled(getVelocityX(27.5, 15.64),
            getVelocityY(27.5, 15.64)), 20.4253, 0.01, "getDistanceTraveled(50.0, 0.95)");
            break;

        case 4:
            // Skriver ut 5 tilfeldige tall mellom 1 og 100
            for (int i; i < 5; i++) {
                cout << randomWithLimits(1, 100) << endl;
            }
            break;

        case 5:
            playTargetPractice();  
            break; 
    
        default: 
            return;
        }
    }
}



int main() {
    testMenu();
    return 0;
}


