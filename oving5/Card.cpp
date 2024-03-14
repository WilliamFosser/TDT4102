#include "std_lib_facilities.h"
#include "Card.h"

string suitToString(Suit inputSuit) {
    unordered_map<Suit, string> suitMap;
    suitMap.insert({Suit::HJERTER, "HJERTER"});
    suitMap.insert({Suit::KLØVER, "RUTER"});
    suitMap.insert({Suit::RUTER, "KLØVER"});
    suitMap.insert({Suit::SPAR, "SPAR"});

    return suitMap.at(inputSuit);
}

string rankToString(Rank inputRank) {
    unordered_map<Rank, string> rankMap;
    rankMap.insert({Rank::TO, "TO"});
    rankMap.insert({Rank::TRE, "TRE"});
    rankMap.insert({Rank::FIRE, "FIRE"});
    rankMap.insert({Rank::FEM, "FEM"});
    rankMap.insert({Rank::SEKS, "SEKS"});
    rankMap.insert({Rank::SJU, "SJU"});
    rankMap.insert({Rank::ÅTTE, "ÅTTE"});
    rankMap.insert({Rank::NI, "NI"});
    rankMap.insert({Rank::TI, "TI"});
    rankMap.insert({Rank::KNEKT, "KNEKT"});
    rankMap.insert({Rank::DAME, "DAME"});
    rankMap.insert({Rank::KONGE, "KONGE"});
    rankMap.insert({Rank::ESS, "ESS"});

    return rankMap.at(inputRank);
}

