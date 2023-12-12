//
// Created by ASUS on 11/2/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_SCOREHAND_H
#define ANALOG_DIGITAL_CLOCK_SCOREHAND_H

#include "vector"
#include "iostream"

enum Scores {

    ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

    STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

    FOUR_OF_A_KIND, //four cards of the same ranking

    FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

    FLUSH, //five cards of the same suit

    STRAIGHT, //five cards in consecutive ranking

    THREE_OF_A_KIND, //three cards of the same rank

    TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

    ONE_PAIR, //two cards of the same rank

    HIGH_CARD //highest card in the player’s hand

};

class ScoreHand {
public:
    ScoreHand();

//    void operator+=(const Scores& score);
//
//    friend bool operator==(const ScoreHand& scoreCard, Scores score);

    int size() const;

    Scores operator[](unsigned int index) const;
    static void addScore(Scores scores);
    static bool isRoyalFlush();
    static void print();
    static int getScore(Scores scores);
private:
    static std::vector<int> scores;

};



#endif //ANALOG_DIGITAL_CLOCK_SCOREHAND_H
