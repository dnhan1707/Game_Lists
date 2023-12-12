//
// Created by ASUS on 11/2/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_GETRANDOMCARD_H
#define ANALOG_DIGITAL_CLOCK_GETRANDOMCARD_H

#include "Card.h"

class getRandomCard {
public:
    getRandomCard();
    void generateRankAndSuit();
    Rank getRandRank();
    Suit getRandSuit();

private:
    Rank rank;
    Suit suit;
};


#endif //ANALOG_DIGITAL_CLOCK_GETRANDOMCARD_H
