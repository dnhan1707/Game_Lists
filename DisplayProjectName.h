//
// Created by ASUS on 12/9/2023.
//

#ifndef SFML_PROJECT_DISPLAYPROJECTNAME_H
#define SFML_PROJECT_DISPLAYPROJECTNAME_H

#include "SFML/Graphics.hpp"
#include "StatesPortfolio.h"
#include "FontPorfolio.h"
#include "PositionPortfolio.h"
class DisplayProjectName : public sf::Drawable, public StatesPortfolio
{
private:
    sf::Text text;
    sf::RectangleShape box;
    int limit;
    DisplayProjectName(sf::Vector2f display_screen, sf::Font& font, unsigned int characterSize, sf::Color color, sf::Vector2f position, int limit, bool trackTime);

public:
    DisplayProjectName();
    DisplayProjectName(sf::Vector2f display_screen, sf::Font& font, unsigned int characterSize);

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
};


#endif //SFML_PROJECT_DISPLAYPROJECTNAME_H
