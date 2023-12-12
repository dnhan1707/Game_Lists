//
// Created by ASUS on 11/2/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_CARDHANDSCORER_H
#define ANALOG_DIGITAL_CLOCK_CARDHANDSCORER_H

#include "CardHand.h"
#include "ScoreHand.h"
#include "vector"

class CardHandScorer {
public:
    CardHandScorer();
    CardHandScorer(CardHand cardHand);

    void calculateNumDup();
    void calculateUnique();
    const int& getUniqueCard() const;
    const int& getNumDup() const;


    bool isConsecutiveRank();
    bool isAllSameSuite();
    bool hasRoyalFlush();

    bool hasFourOfAKind();
    bool hasTwoPairs();
    bool hasOnePair();

    bool hasFullHouse();
    bool hasThreeOfAKind();

    bool hasStraightFLush();
    bool hasFlush();
    bool hasStraight();

    void identifyHand();


private:
    bool isConsecutive;
    bool isAllSameSuit;
    CardHand cardHand;
    int num_unique;
    int num_dup;
};


#endif //ANALOG_DIGITAL_CLOCK_CARDHANDSCORER_H
