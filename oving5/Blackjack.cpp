#include "std_lib_facilities.h"
#include "Card.h"
#include "CardClass.h"
#include "Blackjack.h"
#include "CardDeck.h"

Blackjack::Blackjack() {
    playerScore = 0;
    dealerScore = 0;
    deck.shuffle();
}

void Blackjack::initialDeal() {
    playerHand.push_back(deck.drawCard());
    playerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());
}


void Blackjack::playBlackjack() {  

    initialDeal();
    cout << "Du spiller nå blackjack!" << endl;
    cout << "Du får to kort" << endl;

    printPlayerHand();
    calculateScore();

    cout << "Din score er: " << playerScore << endl;
    cout << "-----------------" << endl;
    cout << "Dealeren får to kort: " << endl;
    cout << "Dealerens første kort er: " << dealerHand.at(0).toString() << endl;
    cout << "-----------------" << endl;

    while (playerScore < 21) {
        cout << "\n\nVil du trekke et kort? (ja/nei)" << endl;
        string choice;
        cin >> choice;
        cout << "-----------------" << endl;
        if (choice == "ja") {
            playerHand.push_back(deck.drawCard());
            printPlayerHand();
            calculateScore();
            cout << "Din score er: " << playerScore << endl;
        }
        else {
            break;
        }
    }
    while (dealerScore < 17) {
        dealerHand.push_back(deck.drawCard());
        printDealerHand();
        calculateScore();
        cout << "Dealerens score er: " << dealerScore << endl;
    }
    printGameResoults();
}


void Blackjack::calculateScore() {
    playerScore = 0;
    dealerScore = 0;    
    bool playerCardIsEss; 
    for (Card c : playerHand) {
        int cardValue = c.getCardValueForBlackjack();
        if (cardValue == 11) {
            playerCardIsEss = true;
        }
        else {
            playerScore += cardValue;
        }
    }
    int playerScorePlus11 = playerScore + 11;
    if (playerScorePlus11 > 21 && playerCardIsEss) {
        playerScore += 1;
    }
    else if (playerCardIsEss) {
        playerScore += 11;
    }

    bool dealerCardIsEss;
    for (Card c : dealerHand) {
        int cardValue = c.getCardValueForBlackjack();
        if (cardValue == 11) {
            dealerCardIsEss = true;
        }
        else {
            dealerScore += cardValue;
        }
    }
    int dealerScorePlus11 = dealerScore + 11;
    if (dealerScorePlus11 > 21 && dealerCardIsEss) {
        dealerScore += 1;
    }
    else if (dealerCardIsEss) {
        dealerScore += 11;
    }
}


void Blackjack::printPlayerHand() {
    cout << "Kortene dine er: " << endl; 
    cout << "-----------------" << endl;
    for (Card& card : playerHand) {
        cout << card.toString() << endl;
    }
    cout << "-----------------" << endl;
}


void Blackjack::printDealerHand() {
    cout << "Kortene til dealeren er: " << endl; 
    cout << "-----------------" << endl;
    for (Card& card : dealerHand) {
        cout << card.toString() << endl;
    }
    cout << "-----------------" << endl;
}

bool checkIfRealBlackjack(const vector<Card>& hand) {
    bool containsEss = false;
    bool containsKongeDameKnekt = false;
    for (Card c : hand) {
        Rank cardRank = c.getRank();
        if (cardRank == Rank::ESS) {
            containsEss = true;
        }
        if (cardRank == Rank::KONGE || cardRank == Rank::DAME || cardRank == Rank::KNEKT) {
            containsKongeDameKnekt = true;
        }
    }
    if (containsEss && containsKongeDameKnekt) {
        return true;
    }
    else {
        return false;
    }
}

bool Blackjack::checkIfPlayerWins() {

    bool playerHigherThanDealer = ((playerScore > dealerScore) &&  playerScore < 21);
    bool dealerOver21 = (dealerScore > 21 && playerScore <= 21);

    if (checkIfRealBlackjack(playerHand) && !checkIfRealBlackjack(dealerHand)) {
        cout << "Du har blackjack!" << endl;
        return true;
    }
    else if (playerHigherThanDealer) {
        cout << "Du har høyere score enn dealeren!" << endl;
        return true;
    }
    else if (dealerOver21) {
        cout << "Dealeren har over 21!" << endl;
        return true;
    }
    else {
        return false;
    }
}


void Blackjack::printGameResoults() {
    if (checkIfPlayerWins()) {
        cout << "Gratulerer, du vant!" << endl;
    }
    else {
        cout << "\nDealeren vant med disse kortene: " << endl;
        printDealerHand();
        cout << "Din score var: " << playerScore << endl;
        cout << "Dealerens score var: " << dealerScore << endl;
    }
}

