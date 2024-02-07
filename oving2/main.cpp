//  Øving 2 - Oppgave 1

#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Oppgave 1
// a)
void inputAndPrintInteger() {
    cout << "Skriv inn et heltall: "; 
    int inputNumber;
    cin >> inputNumber;
    cout << "Du skrev: " << inputNumber << "\n\n\n";
}

// b)
int inputInteger() {
    cout << "Skriv inn et heltall: "; 
    int inputNumber;
    cin >> inputNumber;
    return inputNumber;
}

// e) valgte å bruke inputInteger() i stedet for inputAndPrintInteger() 
// for å kunne printe kun summen av tallene til skjermen. 
void inputIntegersAndPrintSum() {
    int sum = inputInteger() + inputInteger();
    cout << "Summen av tallene: " << sum << "\n\n\n";
}

bool isOdd(int number) {
    if (number % 2 == 0) {
        return false;
    } else {
        return true;
    }
}

// Oppgave 2
// a)
void printSumOfDefinedNumberOfIntegers() {
    cout << "Antall heltall som skal summeres: ";
    int integersToSum;
    cin >> integersToSum;
    cout << "\nHeltallene som skal summeres:\n\n";
    int sum{0}; 
    for (int i = 0; i < integersToSum; i++) {
        int integer;
        cout << "Tall " << i + 1 << ":  ";
        cin >> integer;
        sum += integer;
    }
    cout << "----------------------" << "\n";
    cout << "Summen av tallene = " << sum << "\n\n\n";
}

// b)
void printSumOfUndefinedNumberOfIntegers() {
    cout << "\nHeltallene som skal summeres:\n\n";
    int sum{0}; 
    int i{0};
    while (true) {
        int integer;
        cout << "Tall " << i + 1 << ":  ";
        cin >> integer;
        if (integer == 0) {
            break;
        } else {
            sum += integer;
            i++;
        }
    }
    cout << "\n----------------------" << "\n";
    cout << "Summen av tallene = " << sum << "\n\n\n";
}

/*
c) 
En for-løkke egner seg best i a) fordi vi vet hvor mange ganger vi skal iterere gjennom løkken.
En while-løkke egner seg best i b) fordi vi ikke vet hvor mange ganger vi skal iterere gjennom løkken. 
og vi ittererer intill betiingelsen er oppfylt. 
*/

// d) 
double inputDouble() {
    cout << "Skriv inn et tall: "; 
    int inputNumber;
    cin >> inputNumber;
    return inputNumber;
}

double roundToTwoDecimals(double num) {
    cout << fixed << setprecision(2);
    return num;
}

// e) 
void nokToEuro() {
    const double exchangeRate = 11.37;
    double nok = inputDouble();
    if (nok < 0) {
        cout << "Du kan ikke konvertere et negativt tall til euro.\n\n\n";
    } else {
        double euro = nok / exchangeRate;
        cout << " NOK = " << roundToTwoDecimals(euro) << " EUR\n\n\n";
    }
} 

// f) Brukte double fordi det skal være mulig å konvvertere kroner og øre til euro. 
//    Returtypen må derfor også være double, for å kunne returnere euro med desimaler. 

// g)
void timesTable() {
    int columns; 
    int rows; 
    cout << "Antall rader: ";
    cin >> rows; 
    cout << "Antall kolonner: ";
    cin >> columns;
    cout << "\n";
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            cout << right << setw(4) << i * j;
        }
        cout << "\n";
    }
    cout << "\n\n\n";
}

// Oppgave 3

// a)
double discrimintant(double a, double b, double c) {
    return pow(b, 2) - 4*a*c;
}

// b)
void printRealRoots(double a, double b, double c) {
    if (discrimintant(a, b, c) > 0) {
        cout << "To reelle løsninger:\n";
        cout << "x1 = " << (-b + sqrt(discrimintant(a, b, c))) / (2*a) << "\n";
        cout << "x2 = " << (-b - sqrt(discrimintant(a, b, c))) / (2*a) << "\n";
    } else if (discrimintant(a, b, c) == 0) {
        cout << "En reell løsning:\n";
        cout << "x = " << -b / 2*a << "\n";
    } else {
        cout << "To imaginære løsninger\n";
    }
    cout << "\n\n\n";
}

// c)
void solveQuadraticEquation() {
    double a, b, c;
    cout << "Skriv inn a: ";
    cin >> a;
    cout << "Skriv inn b: ";
    cin >> b;
    cout << "Skriv inn c: ";
    cin >> c;
    cout << "\n";   
    printRealRoots(a, b, c);
}

// Oppgave 4

// a) 
void pythagoras() {
    int with = 1000;
    int height = 1000;
    AnimationWindow win{100,100, with, height, "Pythagoras"};

    Point point1{400, 300};
    Point point2{400, 600};
    Point point3{600, 600};
    win.draw_triangle(point1, point2, point3, Color::black);

    Point point4{400, 300};
    Point point5{100, 300};
    Point point6{100, 600};
    Point point7{400, 600};
    win.draw_quad(point4, point5, point6, point7, Color::green);

    Point point8{400, 600};
    Point point9{600, 600};
    Point point10{600, 800};
    Point point11{400, 800};
    win.draw_quad(point8, point9, point10, point11, Color::red);

    Point point12{400, 300};
    Point point13{600, 600};
    Point point14{600+300, 600-200};
    Point point15{400+300, 300-200};
    win.draw_quad(point12, point13, point14, point15, Color::blue);

    
    win.draw_text(Point{480, 570}, "A", Color::white);
    win.draw_text(Point{400, 450}, "B", Color::white);
    win.draw_text(Point{470, 450}, "C", Color::white);

    win.wait_for_close(); 
}

// Oppgave 5

// a)
vector<int> calculateBalance(double balance, int interest, int years) {
    vector<int> balanceVector(0);
    for (int i = 0; i < years; i++) {
        balanceVector.push_back(balance);
        balance += balance * interest/100;
    }
    return balanceVector;
}

// b)
void printBalanceVector(vector<int> balanceVector) {
    cout << "År:" << setw(10) << "Saldo:" << "\n";
    cout << "--------------\n";
    for (int year = 0; year < balanceVector.size(); year++) {
        cout << left << year << setw(5) << right << setw(10)<< balanceVector.at(year) << "\n";
    }
    cout << "\n\n\n";
}

// c) Feilen kan kannskje skyldes at man prøver å skrive ut vektoren dirrekte, uten å itterere over hvert element. 

// d) 
void printDefinedListElements() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
    cout << "\n\n\n"; 
}
// Fikk ingen feilkoder, men programmet stopper aldri hvis man ikke bygger ut "<=" med "<" i for-løkken.


void testMenu() {
    while (true) {
        cout    << "Velg funksjon for testing:\n"
                << "0)\tAvslutt\n"
                << "1)\tLeser inn og skriver ut heltall\n"
                << "2)\tReturnerer heltallet du skriver inn\n"
                << "3)\tSummerer to tall\n"
                << "4)\tSkjekker for oddetall på intervallet [0, 15]\n"
                << "5)\tSummerer bestemt antall heltall\n"
                << "6)\tSummerer heltall helt til du angir null\n"
                << "7)\tKonverter fra NOK til EURO\n"
                << "8)\tSkriver ut gangetabell med definert størrelse\n"
                << "9)\tSkriver ut løsningene til andregradslikninger\n"
                << "10)\tLøser andregradslikninger\n"
                << "11)\tVisualiserer Pythagoras læresetning\n"
                << "12)\tSkriver ut saldo for hvert år\n"
                << "13)\tSkriver ut elementene i en liste\n\n"
                << "Angi valg (0-13): ";
        
        int menuChoice, number;
        cin >> menuChoice;
        cout << "\n";

        switch (menuChoice) {
        case 1:
            inputAndPrintInteger(); 
            break;
        case 2:
            number = inputInteger();
            cout << "Funksjonen returnerte: " << number << "\n\n\n";
            break;
        case 3:
            inputIntegersAndPrintSum();
            break;
        case 4:
            for (int i = 0; i <= 15; i++) {
                cout << setw(2) << i << " - " << (isOdd(i) ? "true" : "false") << "\n";
            }
            cout << "\n\n\n";
            break;  
        case 5:
            printSumOfDefinedNumberOfIntegers();
            break;
        case 6:
            printSumOfUndefinedNumberOfIntegers();
            break;  
        case 7:
            nokToEuro();
            break;
        case 8:
            timesTable();
            break;
        case 9:
            printRealRoots(1, 1, 5);
            break;
        case 10:
            solveQuadraticEquation();
            break;
        case 11:
            pythagoras();
            break;  
        case 12: 
            printBalanceVector(calculateBalance(5000, 5, 10));
            break;
        case 13:
            printDefinedListElements();
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

