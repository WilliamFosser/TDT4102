#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "CardClass.h"



class Blackjack {
    private: 
    vector<Card> playerHand;
    vector<Card> dealerHand; 
    int playerScore; 
    int dealerScore;  
    CardDeck deck;
    
    void calculateScore();
    void printPlayerHand();
    void printDealerHand();
    void printGameResoults();
    void initialDeal();


    public: 
    Blackjack();
    void playBlackjack();
    bool checkIfPlayerWins();
    
};

bool checkIfRealBlackjack(const vector<Card>& hand);


// bool isEss(Card& c); 