#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class Card {
private: 
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    string toString();
    int getCardValueForBlackjack();
};



