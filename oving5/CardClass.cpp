#include "std_lib_facilities.h"
#include "CardClass.h"
#include "Card.h"

Card::Card(Suit suit, Rank rank): s{suit}, r{rank}
{}

Suit Card::getSuit() {
    return s;
}

Rank Card::getRank() {
    return r;
}

string Card::toString() {
    return suitToString(s) + " " + rankToString(r);
}


int Card::getCardValueForBlackjack() {

    switch (r) {
        case Rank::KNEKT:
            return 10;
            break;
        case Rank::DAME:
            return 10;
            break;
        case Rank::KONGE:
            return 10;
            break;
        default:
            return static_cast<int>(r);
            break;
    }
}

