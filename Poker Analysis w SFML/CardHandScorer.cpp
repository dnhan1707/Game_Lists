//
// Created by ASUS on 11/2/2023.
//

#include "CardHandScorer.h"


CardHandScorer::CardHandScorer()
{

}

CardHandScorer::CardHandScorer(CardHand cardHand)
        :cardHand(cardHand)
{

}

bool CardHandScorer::isAllSameSuite()
{
    bool sameSuit = true;
    std::vector<Card> cards = cardHand.player_card;

    for (int idx = 0; idx < 4; ++idx) {
        if (cards[idx].getSuit() != cards[idx+1].getSuit())
        {
            sameSuit = false;
            break;
        }
    }

    return sameSuit;
}


void CardHandScorer::calculateUnique()
{
    num_unique = 0;
    std::vector<Card> cards = cardHand.player_card;

    for (int idx = 0; idx < 5; ++idx) {
        bool is_unique = true;

        for (int i = idx+1; i < 5; ++i) {
            if (i != idx && cards[idx].getRank() == cards[i].getRank())
            {
                is_unique = false;
                break;
            }
        }

        if (is_unique)
        {
            num_unique++;
        }
    }
}

void CardHandScorer::calculateNumDup()
{
    num_dup = 0;
    int count = 1;
    std::vector<Card> cards = cardHand.player_card;

    Card& prev = cards.front();

    for (int i = 1; i < cards.size(); i++) {
        if(prev.getRank() == cards[i].getRank())
        {
            count++;
        }
        if(count > num_dup)
        {
            num_dup = count;
        }
        else
        {
            count = 1;
        }
        prev = cards[i];
    }
}


const int& CardHandScorer::getUniqueCard() const
{
    return num_unique;
}

const int& CardHandScorer::getNumDup() const
{
    return num_dup;
}


bool CardHandScorer::isConsecutiveRank()
{
    isConsecutive = true;
    std::vector<Card> cards = cardHand.player_card;

    int idx = 0;
    while (isConsecutive && idx != cards.size()-1){
        if (cards[idx+1].getRank() - cards[idx].getRank() == 1)
        {
            idx++;
        }
        else isConsecutive = false;
    }
    return isConsecutive;
}

void CardHandScorer::identifyHand()
{
    if (hasRoyalFlush())
    {
        ScoreHand::addScore(ROYAL_FLUSH);
        ScoreHand::addScore(STRAIGHT_FLUSH);
        ScoreHand::addScore(FLUSH);
        ScoreHand::addScore(STRAIGHT);
    }
    else if (hasFourOfAKind())
    {
        ScoreHand::addScore(FOUR_OF_A_KIND);
        ScoreHand::addScore(TWO_PAIR);
        ScoreHand::addScore(ONE_PAIR);

    }
    else if (hasTwoPairs())
    {
        ScoreHand::addScore(TWO_PAIR);
        ScoreHand::addScore(ONE_PAIR);

    }
    else if (hasOnePair())
    {
        ScoreHand::addScore(ONE_PAIR);
    }

    else if(hasFullHouse())
    {
        ScoreHand::addScore(FULL_HOUSE);
        ScoreHand::addScore(THREE_OF_A_KIND);
        ScoreHand::addScore(ONE_PAIR);
    }
    else if(hasThreeOfAKind())
    {
        ScoreHand::addScore(THREE_OF_A_KIND);
        ScoreHand::addScore(ONE_PAIR);
    }
    else if(hasStraightFLush())
    {
        ScoreHand::addScore(STRAIGHT_FLUSH);
        ScoreHand::addScore(FLUSH);
        ScoreHand::addScore(STRAIGHT);

    }
    else if(hasFlush())
    {
        ScoreHand::addScore(FLUSH);
    }
    else if(hasStraight())
    {
        ScoreHand::addScore(STRAIGHT);

    }
    ScoreHand::addScore(HIGH_CARD);

}

bool CardHandScorer::hasRoyalFlush()
{
    std::vector<Card> cards = cardHand.player_card;
    if (cards[0].getRank() == ACE && cards[1].getRank() == TEN && cards[2].getRank() == JACK && cards[3].getRank() == QUEEN && cards[4].getRank() == KING
        && isAllSameSuite())
        return true;
    return false;

}

bool CardHandScorer::hasFourOfAKind()
{
    if (num_dup == 4 && num_unique == 2)
    {
        return true;
    } return false;
}
bool CardHandScorer::hasTwoPairs()
{
    if (hasFourOfAKind() || (num_dup == 2 && num_unique == 3))
    {
        return true;
    } else return false;
}
bool CardHandScorer::hasOnePair(){
    if (hasFourOfAKind() || hasTwoPairs() || (num_dup == 2 && num_unique == 4))
    {
        return true;
    }return false;
}

bool CardHandScorer::hasFullHouse()
{
    if (num_dup == 3 && num_unique == 2)
    {
        return true;
    }return false;
}

bool CardHandScorer::hasThreeOfAKind()
{
    if (hasFourOfAKind() || (num_dup == 3 && num_unique == 3))
    {
        return true;
    } return false;
}


bool CardHandScorer::hasStraightFLush()
{
    if (isConsecutiveRank() && isAllSameSuite())
    {
        return true;
    } return false;
}

bool CardHandScorer::hasFlush()
{
    if (isConsecutiveRank())
    {
        return true;
    } return false;
}

bool CardHandScorer::hasStraight()
{
    if (isConsecutiveRank())
    {
        return true;
    } return false;
}
