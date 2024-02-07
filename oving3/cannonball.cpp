#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball_viz.h"

double acclY() {
    return -9.81;         // m/s^2
}

double velY(double initVelocity, double time) {
    double velocityY = initVelocity + acclY()*time;
    return velocityY;
}

double posX(double initPositionX, double initVelocityX, double time) {
    double positionX = initPositionX + initVelocityX*time;
    return positionX;
}

double posY(double initPositionY, double initVelocityY, double time) {
    double positionY = initPositionY + initVelocityY*time + acclY()*pow(time, 2)*0.5;
    return positionY;
}


void printTime(double time) {
    int hours = static_cast<int>(time) / 3600;           
    int minutes = (static_cast<int>(time) % 3600) / 60;        
    double seconds = time - (hours * 3600) - (minutes * 60);
    cout << hours << " Timer,  " << minutes 
    << " Minutter,  " << fixed << setprecision(2) << seconds << " Sekunder  " << endl;
}

double flightTime(double initVelocityY) {
    double time = (-2 * initVelocityY) / acclY();
    return time;
}

// Ber brukeren om en vinkel i grader
double getUserInputTheta() {
    double theta;
    cout << "Skriv inn en vinkel i grader: ";
    cin >> theta;
    return theta;
}

//Ber brukeren om en startfart
double getUserInputInitVelocity(){
    double initVelocity;
    cout << "Skriv inn en startfart: ";
    cin >> initVelocity;
    return initVelocity;
}

// Konverterer fra grader til radianer
double degToRad(double deg) {
    return deg * (M_PI / 180);
}

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity) {
    double thetaRad = degToRad(theta);
    double velocityX = initVelocity * cos(thetaRad);
    return velocityX;
}

double getVelocityY(double theta, double initVelocity) {
    double thetaRad = degToRad(theta);
    double velocityY = initVelocity * sin(thetaRad);
    return velocityY;
}

// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> makeVelocityVector(double theta, double initVelocity) {
    vector<double> velocityVector;
    velocityVector.push_back(getVelocityX(theta, initVelocity));
    velocityVector.push_back(getVelocityY(theta, initVelocity));
    return velocityVector;
}

double getDistanceTraveled(double velocityX, double velocityY) {
    double distanceTraveled = posX(0, velocityX, flightTime(velocityY));
    return distanceTraveled;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double deviation = distanceToTarget - getDistanceTraveled(velocityX, velocityY);
    return deviation;
}

void playTargetPractice() {
    int targetDistance = randomWithLimits(100, 1000);
    for (int attempt = 0; attempt < 10; attempt++) {
        double theta = getUserInputTheta();
        double initVelocity = getUserInputInitVelocity();
        vector<double> velocityVector = makeVelocityVector(theta, initVelocity);
        double deviation = targetPractice(targetDistance, velocityVector.at(0), velocityVector.at(1));
        if (deviation <= 5) {
            cout << "Gratulerer! Du traff malet!" << endl;
            return;
        }
        else {
            if (deviation > 0) {
                cout << "Du skøyt " << abs(deviation) << " meter for kort" << endl;
            }
            else
            cout << "Du skøyt " << abs(deviation) << " meter for langt" << endl;
        }
    cout << "Du har " << 9 - attempt << " forsøk igjen" << endl;
    cout << "Kula var i lufta i: ";
    printTime(flightTime(velocityVector.at(1)));
    cout << endl; 
    cannonBallViz(targetDistance, 1000, velocityVector.at(0), velocityVector.at(1), 1000);

    }
    cout << "Du traff ikke målet på 10 forsøk, og har dermed tapt spillet" << endl;
    cout << "Prøv igjen, så klarar du det sikkert!" << endl;   
}

