//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_DISPLAYGALAGA_H
#define SFML_PROJECT_DISPLAYGALAGA_H

#include "SFML/Graphics.hpp"
#include "FontGalaga.h"
#include "StatesGalaga.h"
#include "PositionGalaga.h"

class DisplayGalaga : public sf::Drawable, public StatesGalaga
{
private:
    sf::Text text;
    sf::RectangleShape box;
    sf::Clock clock;  // Added clock for time tracking

    int limit; //since we have limit for setter setCharacter

    DisplayGalaga(sf::Vector2f display_screen, sf::Font& font, unsigned int characterSize, sf::Color color, sf::Vector2f position, int limit, bool trackTime);


public:
    DisplayGalaga();
//    DisplayGalaga(const sf::Text &text);
    DisplayGalaga(sf::Vector2f display_screen, sf::Font& font, unsigned int characterSize);

    void show();
    void clear();
    void setText(const std::string& text);
    std::string getText();
    void setCharacterLimit(int limit);
    void setColor(sf::Color color);
    void setFont(const sf::Font& font);
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setTextPosition(sf::Vector2f position);
    sf::Text& getTextObject();

    void setCharacterSize(unsigned int size);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    sf::RectangleShape& getDisplayBox();
    void update();

    // Function to get elapsed time as a string
    std::string getElapsedTimeAsString();
};


#endif //SFML_PROJECT_DISPLAYGALAGA_H
