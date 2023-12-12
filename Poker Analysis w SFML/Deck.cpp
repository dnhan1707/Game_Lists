//
// Created by ASUS on 11/2/2023.
//

#include "Deck.h"

Deck::Deck()
{

}

void Deck::shuffle()
{
    for (int i = 0; i < DECK_SIZE; ++i) {
        deck[i] =  Card(Rank(i % 13), Suit(i % 4));
    }


    for (int i = DECK_SIZE - 1; i > 0; --i) {
        // Generate a random index within the remaining unshuffled cards
        int j = rand() % (i + 1);

        // Swap the cards at indices i and j
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    // Reset the cardIndex
    cardIndex = 0;
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    out << deck.rankToString() << " of " << deck.suitToString();
    return out;
}

Card Deck::dealCard()
{
    return deck[cardIndex++];
}

Card Deck::getCardAt(int index)
{
    return deck[index];
}


bool Deck::empty()
{
    return cardIndex >= DECK_SIZE;
}


std::string Deck::rankToString() const
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
std::string Deck::suitToString() const
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
