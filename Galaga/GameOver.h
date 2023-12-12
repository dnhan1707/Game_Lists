//
// Created by ASUS on 12/7/2023.
//

#ifndef SFML_PROJECT_GAMEOVER_H
#define SFML_PROJECT_GAMEOVER_H

#include "SFML/Graphics.hpp"
#include "FontGalaga.h"
#include "ButtonGalaga.h"
#include "BackgroundGalaga.h"
#include "StatesGalaga.h"

class GameOver : public sf::Drawable, public StatesGalaga
{
private:
    sf::RectangleShape background;
    sf::Text gameOverText;
    sf::Text longestSurvivalText;
    sf::Text restartText;
    ButtonGalaga button;
public:
    GameOver();
    GameOver(sf::Vector2f screenSize, sf::Font& font);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setLongestSurvivalTime(const std::string& time);
    sf::RectangleShape& getGameOverBackground();
    void update();
    void setPosition(sf::RectangleShape& background);
};


#endif //SFML_PROJECT_GAMEOVER_H
