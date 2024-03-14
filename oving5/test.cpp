#include "std_lib_facilities.h"
#include "Card.h"
#include "CardClass.h"
#include "CardDeck.h"
#include "Blackjack.h"

void testMenu() {

    while (true) {
        cout << "Velg hvilke funksjon du ønsker å teste: \n"
             << "1) Tester suitToString(Suit::HJERTER) \n"
             << "2) Tester rankToString(Rank::KNEKT) \n"
             << "3) Tester klassen Card og metoden toString()\n"
             << "4) Tester klassen CardDeck og metoden shuffle()\n"
             << "5) Spiller blackjack\n"
             << "6) Avslutt\n";


        int menuChoice;
        cin >> menuChoice;
        cout << endl;

        switch (menuChoice)
        {
        case 1:
            cout << "Returverdien skal være HJERTER" << endl;
            if (suitToString(Suit::HJERTER) == "HJERTER") {
                cout << "Funksjonen funger som den skal, og returnerte: " << suitToString(Suit::HJERTER) << endl; 
            }
            else {
                cout << "Funksjonen fungerte ikke som den skulle" << endl; 
            }
            break;

        case 2:
        cout << "Returverdien skal være KNEKT" << endl;
            if (rankToString(Rank::KNEKT) == "KNEKT") {
                cout << "Funksjonen funger som den skal, og returnerte: " << rankToString(Rank::KNEKT) << endl; 
            }
            else {
                cout << "Funksjonen fungerte ikke som den skulle" << endl; 
            }
            break;

        case 3: {
            cout << "Kortet c = SPAR ESS opprettes" << endl; 
            Card c {Suit::SPAR, Rank::ESS};
            if (c.toString() == "SPAR ESS") {
                cout << "Funksjonen funger som den skal, og skriver ut: " << c.toString() << endl; 
            }
            else {
                cout << "Klassen eller metoden fungerte ikke som den skulle" << endl;
            }
            break;
        }

        case 4: {
            CardDeck deck; 
            deck.print();
            deck.shuffle();
            deck.print();
            break;
        }

        case 5: {
            Blackjack game;
            game.playBlackjack();
            break;
        }

        default:
            cout << "\n\n";
            return;
        }
    }
}