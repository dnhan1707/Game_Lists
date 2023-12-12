//
// Created by ASUS on 10/17/2023.
//

#ifndef FRIEND_FUNCTION_CARD_H
#define FRIEND_FUNCTION_CARD_H

#include "Rank.h"
#include "Suit.h"
#include "iostream"
#include "ctime"
/// ACE = 1 OR 11;
/// QUEEN, JACK, KING = 10;
/// OTHERS worth the face value;

class Card
{
public:
    Card();
    Card(Rank rank, Suit suit);


    friend std::ostream& operator << (std::ostream& out, const Card& card);
    std::string rankToString() const;
    std::string suitToString() const;


    // + operator;
    friend int operator + (const Card& card_1, const Card& card_2);
    // - operator;
    friend int operator - (const Card& card_1, const Card& card_2);

    // = operator
    Card& operator = (const Card& card);

    // ++ operator
    Card operator ++ (int);   // x++
    Card& operator ++ ();     // ++x

    // -- operator
    Card operator -- (int);   // x--
    Card& operator -- ();     // --x

    // += operator
    Card& operator += (int num);
    Card& operator -= (int num);

    // == operator
    friend bool operator == (const Card& card_1, const Card& card_2);

    // != operator
    friend bool operator != (const Card& card_1, const Card& card_2);

    const Rank& getRank() const;
    const Suit& getSuit() const;

private:
    Rank rank;
    Suit suit;
    int getRankValue() const;
};


#endif //FRIEND_FUNCTION_CARD_H
