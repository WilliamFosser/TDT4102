#include "std_lib_facilities.h"
#include "Card.h"
#include "CardClass.h"
#include "CardDeck.h"

// Konstruktør - fyller kortstokken med alle 52 kortene. 
CardDeck::CardDeck() {
    for (int suit = 0; suit < 4; suit++) {
        Suit cardSuit = static_cast<Suit>(suit);

        for (int rank = 2; rank < 14; rank++) {
            Rank cardRank = static_cast<Rank>(rank);

            cards.push_back(Card(cardSuit, cardRank));
        }
    }
}

// Bytter to kort i kortstokken med to indekser som argumenter. 
void CardDeck::swap(const int index1, const int index2) {
    Card cardAtIndex1 = cards.at(index1);
    Card cardAtIndex2 = cards.at(index2);
    cards.at(index1) = cardAtIndex2;
    cards.at(index2) = cardAtIndex1;
}

// Printer ut kortene i kortstokken.
void CardDeck::print() {
    cout << "Kortene i kortstokken er: " << endl; 
    cout << "-------------------------" << endl;

    for (Card& card : cards) {  // spørre studass hvorfor det ikke fungerer med "const Card& card"
        cout << card.toString() << endl;
    }
}

// implementerte random number generator som generell funksjon.
int CardDeck::randomWithLimits(int lowerLimit, int upperLimit) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(lowerLimit, upperLimit);

    int randomNumber = distribution(generator);
    return randomNumber;    
}

// Kjører swap funksjonen swapIteration = 1000 ganger, med vilkårlige indeksen mellom 0 og cards.size()
void CardDeck::shuffle() {
    int swapIterations = 1000;
    int cardsSize = cards.size()-1;
    for (int i = 0; i < swapIterations; i++) {
        swap(randomWithLimits(0, cardsSize), randomWithLimits(0, cardsSize));
    }
}

// Trekker et kort, og seltter kortet fra kortstokken.
Card CardDeck::drawCard() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

/*
Hvordan gjør jeg dette, samtidig som jeg skjekker om listen er tom først?
Kan jo altids legge til et "feilmeldingkort", men....

Card CardDeck::drawCard() {
    if (!cards.empty()) {
        Card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }
    return HVA????;
}
Får feilkode fordi den ikke returnerer noe hvis if betingelsen ikke holder.

*/