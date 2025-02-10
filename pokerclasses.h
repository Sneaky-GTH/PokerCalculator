#ifndef POKER_CLASSES_H
#define POKER_CLASSES_H

#include <map>
#include <vector>
#include <string>

enum Suit {
    DIAMOND,
    CLUB,
    HEART,
    SPADE
};


// All card ranks.
// ACE = 1, all further values automatically increment.
enum Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};


class PlayingCard {

    private:
        Suit cardSuit;
        Rank cardRank;

    public:
        PlayingCard(Suit newSuit, Rank newRank);
        void setCardSuit(Suit newCardSuit);
        Suit getCardSuit();
        void setCardRank(Rank newCardRank);
        Rank getCardRank();

};


class PlayingCardDeck {

    private:
        std::vector<PlayingCard*> cardDeck;
        int deckSuitAmount {4};
        int deckRankAmount {13};

    public:
        ~PlayingCardDeck();
        std::vector<PlayingCard*> getCardDeck();
        void addPlayingCardToDeck(PlayingCard* newCard);
        PlayingCard* getSpecificCardFromDeck(int givenIndex);
        int getDeckSuitAmount();
        int getDeckRankAmount();

};


class PokerDisplayMaps {
    private:
        std::map<Suit, std::string> suitDisplayMap;
        std::map<Rank, char> rankDisplayMap;

    public:
        PokerDisplayMaps();
        std::map<Suit, std::string> getSuitDisplayMap();
        std::map<Rank, char> getRankDisplayMap();
};


class PokerGame {
    private:
        PokerDisplayMaps displayMaps;
    
    public:
        void getCardAndDisplayIt(PlayingCardDeck* targetCardDeck, int cardIndex);
        void createFullDeck(PlayingCardDeck* targetCardDeck);
};



#endif