//
// Created by ASUS on 10/17/2023.
//

#include "Card.h"



Card::Card()
{

}

Card::Card(Rank rank, Suit suit)
:rank(rank), suit(suit)
{

}

std::ostream& operator <<(std::ostream& out, const Card& card)
{
    out << card.rankToString() << " of " << card.suitToString();
    return out;
}


std::string Card::suitToString() const
{
    switch (suit) {
        case HEART:
            return "HEART";
        case DIAMOND:
            return "DIAMOND";
        case CLUBS:
            return "CLUBS";
        case SPADES:
            return "SPADES";
        default:
            return "Invalid Suit";  // Provide a default case or error handling
    }
}


std::string Card::rankToString() const
{
    switch (rank) {
        case ACE:
            return "ACE";
        case TWO:
            return "TWO";
        case THREE:
            return "THREE";
        case FOUR:
            return "FOUR";
        case FIVE:
            return "FIVE";
        case SIX:
            return "SIX";
        case SEVEN:
            return "SEVEN";
        case EIGHT:
            return "EIGHT";
        case NINE:
            return "NINE";
        case TEN:
            return "TEN";
        case JACK:
            return "JACK";
        case QUEEN:
            return "QUEEN";
        case KING:
            return "KING";
        default:
            return "Invalid rank";
    }
}


// + operator;
int operator + (const Card& card_1, const Card& card_2)
{
    return card_1.getRankValue() + card_2.getRankValue();
}
// - operator;
int operator - (const Card& card_1, const Card& card_2)
{
    return card_1.getRankValue() - card_2.getRankValue();
}

// = operator
Card& Card::operator = (const Card& card)
{
    this->rank = card.rank;
    this->suit = card.suit;
    return *this;
}

// ++ operator
Card Card::operator ++ (int)   // x++, postfix
{
    Card temp = *this;
    rank = Rank((rank + 1) % (KING+1));
    return temp;
}
Card& Card::operator ++ ()   // ++x, prefix
{
    rank = Rank((rank + 1) % (KING+1));
    return *this;
}

// -- operator
Card Card::operator -- (int)   // x--
{
    Card temp = *this;
    rank = Rank((rank + KING) % (KING+1));
    return temp;
}
Card& Card::operator -- ()     // --x
{
    rank = Rank((rank + KING) % (KING+1));
    return *this;
}

// += operator
Card& Card::operator += (int num)
{
    rank = Rank((rank + num) % (KING+1));
    return *this;
}

Card& Card::operator -= (int num)
{
    if (num < 0)
    {
        return operator+=(abs(num));
    }
    rank = Rank((rank - ((num-1) % (KING+1)) + KING) % (KING+1));
    return *this;
}

// == operator
bool operator == (const Card& card_1, const Card& card_2)
{
    return card_1.rank == card_2.rank && card_1.suit == card_2.suit;
}

// != operator
bool operator != (const Card& card_1, const Card& card_2)
{
    return !operator==(card_1, card_2);
}

int Card::getRankValue() const
{
    if (rank < TEN)
    {
        return rank + 1;
    }
    else return 10;
}


const Rank& Card::getRank() const
{
    return rank;
}

const Suit& Card::getSuit() const
{
    return suit;
}
