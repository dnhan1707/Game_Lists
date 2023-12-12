//
// Created by ASUS on 11/2/2023.
//

#include "CardHand.h"


CardHand::CardHand() {

}


Card CardHand::getCardAtFromHand(int index) const
{
    return player_card[index];
}


void CardHand::giveCardsToPlayer(Deck& deck)
{
    while (idx_picked.size() < NUMBER_OF_CARD)
    {
        bool already_picked = false;

        int rand_index = rand() % 52;

        for (int i : idx_picked) {
            if (rand_index == i)
            {
                already_picked = true;
                break;
            }
        }

        if (!already_picked)
        {
            idx_picked.push_back(rand_index);
        }
    }


    for (int i = 0; i < NUMBER_OF_CARD; ++i) {
        player_card.push_back(deck.getCardAt(idx_picked[i]));
    }
    sortCardInAscending();
}


void CardHand::sortCardInAscending() {
    for (int i = 1; i < player_card.size(); ++i) {
        while (i != 0 && player_card[i - 1].getRank() > player_card[i].getRank())
        {
            Card temp = player_card[i - 1];
            player_card[i - 1] = player_card[i];
            player_card[i] = temp;
            i--;
        }
    }
}