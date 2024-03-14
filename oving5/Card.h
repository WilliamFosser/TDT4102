#pragma once
#include "std_lib_facilities.h"

enum class Suit {
    HJERTER, 
    RUTER, 
    KLØVER, 
    SPAR
};

enum class Rank {
    TO = 2, 
    TRE, 
    FIRE, 
    FEM, 
    SEKS, 
    SJU, 
    ÅTTE, 
    NI, 
    TI, 
    KNEKT, 
    DAME, 
    KONGE,
    ESS
};

string suitToString(Suit inputSuit);
string rankToString(Rank inputRank);

