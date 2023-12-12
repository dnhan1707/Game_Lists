//
// Created by ASUS on 11/2/2023.
//

#include "getRandomCard.h"


getRandomCard::getRandomCard()
{

}

void getRandomCard::generateRankAndSuit()
{
    rank = static_cast<Rank>(rand() % 13);
    suit = static_cast<Suit>(rand() % 4);
}


Rank getRandomCard::getRandRank()
{
    generateRankAndSuit();
    return rank;
}

Suit getRandomCard::getRandSuit()
{
    generateRankAndSuit();
    return suit;
}