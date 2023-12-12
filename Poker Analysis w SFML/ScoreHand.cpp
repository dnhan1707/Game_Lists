//
// Created by ASUS on 11/2/2023.
//

#include "ScoreHand.h"

std::vector<int> ScoreHand::scores(10);

ScoreHand::ScoreHand() {

}


void ScoreHand::addScore(Scores score)
{
    scores[score]++;
}


//void ScoreHand::operator += (const Scores& score)
//{
//    scores[static_cast<int>(score)]++;
//}

bool ScoreHand::isRoyalFlush()
{
    if (scores[ROYAL_FLUSH] > 0)
    {

        return true;
    }
    return false;
//    return scores[ROYAL_FLUSH] > 0;
}

//bool operator==(const ScoreHand& scoreCard, Scores score)
//{
//
//}

int ScoreHand::size() const
{
    return static_cast<int>(scores.size());
}

Scores ScoreHand::operator[](unsigned int index) const
{
    return static_cast<Scores>(scores[index]);
}

void ScoreHand::print()
{
    for (int i = 0; i < 10; ++i) {
        switch (i) {
            case ROYAL_FLUSH: std::cout << "Royal flush " << scores[ROYAL_FLUSH] << std::endl;
                break;
            case STRAIGHT_FLUSH: std::cout << "STRAIGHT_FLUSH " << scores[STRAIGHT_FLUSH] << std::endl;
                break;

            case FOUR_OF_A_KIND: std::cout << "FOUR_OF_A_KIND " << scores[FOUR_OF_A_KIND] << std::endl;
                break;

            case FULL_HOUSE: std::cout << "FULL_HOUSE " << scores[FULL_HOUSE] << std::endl;
                break;

            case FLUSH: std::cout << "FLUSH " << scores[FLUSH] << std::endl;
                break;

            case STRAIGHT: std::cout << "STRAIGHT " << scores[STRAIGHT] << std::endl;
                break;

            case THREE_OF_A_KIND: std::cout << "THREE_OF_A_KIND " << scores[THREE_OF_A_KIND] << std::endl;
                break;

            case TWO_PAIR: std::cout << "TWO_PAIR " << scores[TWO_PAIR] << std::endl;
                break;

            case ONE_PAIR: std::cout << "ONE_PAIR " << scores[ONE_PAIR] << std::endl;
                break;

            case HIGH_CARD: std::cout << "HIGH_CARD " << scores[HIGH_CARD] << std::endl;
                break;
        }
    }
}

int ScoreHand::getScore(Scores score)
{
    return scores[score];
}

