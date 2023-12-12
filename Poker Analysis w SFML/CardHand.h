//
// Created by ASUS on 11/2/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_CARDHAND_H
#define ANALOG_DIGITAL_CLOCK_CARDHAND_H

#include "Card.h"
#include "Deck.h"
#include "vector"


class CardHand {
public:
    CardHand();
    std::vector<Card> player_card;
    std::vector<int> idx_picked;

    Card getCardAtFromHand(int index) const;// gets the Card at the given index
    void giveCardsToPlayer(Deck& deck);
    void sortCardInAscending();
private:
    const int NUMBER_OF_CARD = 5;
};


#endif //ANALOG_DIGITAL_CLOCK_CARDHAND_H
