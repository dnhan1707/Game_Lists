//
// Created by ASUS on 11/2/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_DECK_H
#define ANALOG_DIGITAL_CLOCK_DECK_H

#include "Card.h"
#include "iostream"
#include "vector"
class Deck
{
public:
    Deck(); // this is the constructor
    int cardIndex; //marks the index of the next card in the deck
    bool empty(); //returns true if deck has no cards
    Card deck[52];// this is your final deck of cards


    std::string rankToString() const;
    std::string suitToString() const;

    void shuffle(); // puts cards in random order
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console
    Card dealCard(); // returns the next card in the deck
    Card getCardAt(int index);// gets the Card at the given index


private:
    const int DECK_SIZE = 52;// this is the size of your deck
    std::vector<int> num_picked;
    Rank rank;
    Suit suit;
};


#endif //ANALOG_DIGITAL_CLOCK_DECK_H
