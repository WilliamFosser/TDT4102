#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardClass.h"

class CardDeck {
    private: 
    vector<Card> cards;

    int randomWithLimits(int lowerLimit, int upperLimit);

    public: 
    CardDeck();
    void swap(const int index1, const int index2);  // Oppgave 3c) Må være public for å kunne bruke metoden på en kortstokk, men kan være privat hvis den kun brukes som del av shuffle motoden. 
    void print();
    void shuffle();  // - Spørre studas om dette er pass by referance eller ikke. og hvorfor ikke kommentert kode er bra. 
    Card drawCard();
};


