#include <iostream>
#include <string>
#include "pokerclasses.h"


// -----[ PLAYING CARD IMPLEMENTATION]-----

PlayingCard::PlayingCard(Suit newSuit, Rank newRank) {
    this->cardSuit = newSuit;
    this->cardRank = newRank;
}

Rank PlayingCard::getCardRank() {
    return this->cardRank;
}

Suit PlayingCard::getCardSuit() {
    return this->cardSuit;
}

void PlayingCard::setCardRank(Rank newCardRank) {
    this->cardRank = newCardRank;
}

void PlayingCard::setCardSuit(Suit newCardSuit) {
    this->cardSuit = newCardSuit;
}


// -----[PLAYING CARD DECK IMPLEMENTATION]-----


PlayingCardDeck::~PlayingCardDeck() {

    while (this->cardDeck.size() > 0) {
        delete cardDeck[cardDeck.size() - 1];
        cardDeck.pop_back();
    }

}

std::vector<PlayingCard*> PlayingCardDeck::getCardDeck() {
    return this->cardDeck;
}

void PlayingCardDeck::addPlayingCardToDeck(PlayingCard* newCard) {
    this->cardDeck.push_back(newCard);
}

PlayingCard* PlayingCardDeck::getSpecificCardFromDeck(int givenIndex) {   
    return this->cardDeck.at(givenIndex);
}

int PlayingCardDeck::getDeckRankAmount() {
    return this->deckRankAmount;
}

int PlayingCardDeck::getDeckSuitAmount() {
    return this->deckSuitAmount;
}


// -----[POKER DISPLAY MAPS IMPLEMENTATION]-----


PokerDisplayMaps::PokerDisplayMaps() {

    this->suitDisplayMap[DIAMOND] = u8"♦";
    this->suitDisplayMap[CLUB] = u8"♣";
    this->suitDisplayMap[HEART] = u8"♥";
    this->suitDisplayMap[SPADE] = u8"♠";

    this->rankDisplayMap[ACE] = 'A';
    this->rankDisplayMap[TWO] = '2';
    this->rankDisplayMap[THREE] = '3';
    this->rankDisplayMap[FOUR] = '4';
    this->rankDisplayMap[FIVE] = '5';
    this->rankDisplayMap[SIX] = '6';
    this->rankDisplayMap[SEVEN] = '7';
    this->rankDisplayMap[EIGHT] = '8';
    this->rankDisplayMap[NINE] = '9';
    this->rankDisplayMap[TEN] = 'T';
    this->rankDisplayMap[JACK] = 'J';
    this->rankDisplayMap[QUEEN] = 'Q';
    this->rankDisplayMap[KING] = 'K';

}

std::map<Suit, std::string> PokerDisplayMaps::getSuitDisplayMap() {
    return this->suitDisplayMap;
}

std::map<Rank, char> PokerDisplayMaps::getRankDisplayMap() {
    return this->rankDisplayMap;
}


// -----[POKER GAME IMPLEMENTATION]-----


void PokerGame::createFullDeck(PlayingCardDeck* targetCardDeck) {

    int rankCount = targetCardDeck->getDeckRankAmount();
    int suitCount = targetCardDeck->getDeckSuitAmount();
    PlayingCard* newCard;
    Rank newCardRank;
    Suit newCardSuit;

    for (int i = 0; i < suitCount; i++) {
        for (int j = 1; j < rankCount + 1; j++) {
            newCardRank = static_cast<Rank>(j);
            newCardSuit = static_cast<Suit>(i);

            newCard = new PlayingCard(newCardSuit, newCardRank);

            targetCardDeck->addPlayingCardToDeck(newCard);
            std::cout << targetCardDeck->getCardDeck().size() << "\n";
        }
    }

}

void PokerGame::getCardAndDisplayIt(PlayingCardDeck* targetCardDeck, int cardIndex) {
    PlayingCard* cardToDisplay = targetCardDeck->getSpecificCardFromDeck(cardIndex);
    Rank RankToDisplay = cardToDisplay->getCardRank();
    Suit SuitToDisplay = cardToDisplay->getCardSuit();
    char rankChar = this->displayMaps.getRankDisplayMap().at(RankToDisplay);
    std::string suitChar = this->displayMaps.getSuitDisplayMap().at(SuitToDisplay);
    std::cout << suitChar << rankChar << " ";
}