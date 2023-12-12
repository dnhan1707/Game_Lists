//
// Created by ASUS on 12/9/2023.
//

#ifndef SFML_PROJECT_BUTTONPORTFOLIO_H
#define SFML_PROJECT_BUTTONPORTFOLIO_H

#include "SFML/Graphics.hpp"
#include "StatesPortfolio.h"
#include "DisplayProjectName.h"
#include "FontPorfolio.h"
#include "PositionPortfolio.h"
#include "MouseEventsPortfolio.h"

class ButtonPortfolio : public sf::Drawable, public StatesPortfolio
{
private:
    sf::Text text;
    sf::CircleShape circleShape;
    sf::Color defaultColor, clickColor;

    DisplayProjectName display;


public:
    ButtonPortfolio();
    ButtonPortfolio(const std::string& text, sf::Color color);
    ButtonPortfolio(const std::string& text, sf::Color color, sf::Color textColor);

    ButtonPortfolio(const std::string& text, float radius, sf::Color color, sf::Color textColor);
    ButtonPortfolio(const std::string& text, float radius, sf::Font& font, sf::Color color, sf::Color textColor);
    void setupCircle(float radius);
    void setUpText(const std::string &text, sf::Font& font);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void setRadius(float radius);
    void setFont(const sf::Font& font);
    void setText(const std::string& text);
    void setTextColor(sf::Color color);
    std::string getText();
    void setClickColor(sf::Color color);
    void setDefaultColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    void setCharacterSize();
    sf::CircleShape& getButton();

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_BUTTONPORTFOLIO_H
