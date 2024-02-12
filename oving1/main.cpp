// Øving 1 - Oppgave 2

#include "std_lib_facilities.h"


int maxOfTwo(int a, int b) {
	if (a > b) {
	    cout << "A is greater than B" << endl; 
		return a; 
	} else {
		cout << "B is greater than or equal to A" << endl; 
		return b; 
	}
}


int fibonacci(int n) {
	int a = 0; 
	int b = 1;
	cout << "Fibonacci numbers: " << endl;
	for (int x = 1; x < n+1; ++x) {
		cout << x << " " << b << endl;
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----" << endl; 
	return b;
}


int squareNumberSum(int n) {
	int totalSum = 0;
	for (int i = 1; i < n+1; ++i) {
		totalSum += i*i; 
		cout << i*i << endl;
	}
	cout << totalSum << endl; 
	return totalSum;
}


void triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl; 
	while (acc < n) {
		cout << acc << endl; 
		acc += num;
		num += 1;
	}
	cout << endl;
}

// Det er ikke mulig å skrive returverdien til en 
//void-funksjon til skjermen, fordi den ikke har noen returverdi


bool isPrime(int n) {
	for (int j = 2; j < n; ++j) {
		if (n%j == 0) {
			return false;
		}
	}
	return true;
}


void naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n; ++number) {
		if (isPrime(number)) {
			cout << number << " is a prime" << endl;
		}
	}
}


void inputAndPrintNameAndAge() {
	string name = "";
	int age = 0;
	cout << "Skriv inn et navn: ";
	cin >> name;
	cout << "Skriv inn alderen til " << name << ": ";
	cin >> age;
	cout << name << " er " << age << " aar gammel.";
}


int main() {
	cout << "Oppgave a)" << endl;
    cout << maxOfTwo(5, 6) << endl << endl;
    
	cout << "Oppgave c)" << endl;
	cout << fibonacci(5) << endl << endl;

	cout << "Oppgave d)" << endl;
	cout << squareNumberSum(5) << endl << endl;

	cout << "Oppgave e)" << endl;
	triangleNumbersBelow(10);

	cout << "Oppgave f) og g)" << endl;
	naivePrimeNumberSearch(14);
	cout << endl;

	inputAndPrintNameAndAge();
	return 0;
}

