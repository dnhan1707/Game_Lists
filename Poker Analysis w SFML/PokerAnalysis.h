//
// Created by ASUS on 12/9/2023.
//

#ifndef SFML_PROJECT_POKERANALYSIS_H
#define SFML_PROJECT_POKERANALYSIS_H

#include "../Projects.h"
#include "Card.h"
#include "CardHand.h"
#include "Deck.h"
#include "CardHandScorer.h"
#include "ScoreHand.h"
#include "LetterBox.h"
#include "vector"
#include "CardGraphic.h"

class PokerAnalysis : public Projects
{
private:
    float cardSpacing = 20.0f; // Adjust as needed

    std::vector<std::vector<Card>> cardSets;
//    LetterBox letterBox1, letterBox2, letterBox3, letterBox4, letterBox5, letterBox6, letterBox7, letterBox8, letterBox9, letterBox10;

public:
    PokerAnalysis();
    void run();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    std::string getName();
};


#endif //SFML_PROJECT_POKERANALYSIS_H
