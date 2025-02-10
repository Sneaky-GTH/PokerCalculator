#include "pokerclasses.h"
#include <iostream>


int main() {

    std::cout << "Hello!";
    PokerGame newGame;
    PlayingCardDeck newDeck;

    newGame.createFullDeck(&newDeck);
    newGame.getCardAndDisplayIt(&newDeck, 0);
    newGame.getCardAndDisplayIt(&newDeck, 12);
    newGame.getCardAndDisplayIt(&newDeck, 13);
    newGame.getCardAndDisplayIt(&newDeck, 51);
    newGame.getCardAndDisplayIt(&newDeck, 7);
    newGame.getCardAndDisplayIt(&newDeck, 43);
    newGame.getCardAndDisplayIt(&newDeck, 1);
}