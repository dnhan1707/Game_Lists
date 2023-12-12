//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_BUTTONCALCULATOR_H
#define SFML_PROJECT_BUTTONCALCULATOR_H
#include "SFML/Graphics.hpp"
#include "MouseEvents.h"
#include "Font.h"
#include "PositionCalculator.h"
#include "StatesCalculator.h"
#include "DisplayCalculator.h"

class ButtonCalculator : public sf::Drawable, public StatesCalculator
{
private:
    sf::Text text;
    sf::CircleShape circleShape;
    sf::Color defaultColor, clickColor;

    DisplayCalculator display;

    void setupCircle(float radius);
    void setUpText(const std::string &text, sf::Font& font);
    void setCharacterSize();
public:
    ButtonCalculator();
    ButtonCalculator(const std::string& text, sf::Color color);
    ButtonCalculator(const std::string& text, sf::Color color, sf::Color textColor);

    ButtonCalculator(const std::string& text, float radius, sf::Color color, sf::Color textColor);
    ButtonCalculator(const std::string& text, float radius, sf::Font& font, sf::Color color, sf::Color textColor);


    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void setRadius(float radius);
    void setFont(const sf::Font& font);
    void setText(const std::string& text);
    void setTextColor(sf::Color color);
    std::string getText();
    void setClickColor(sf::Color color);
    void setDefaultColor(sf::Color color);
    void setPosition(sf::Vector2f position);

    sf::CircleShape& getButton();

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

};


#endif //SFML_PROJECT_BUTTONCALCULATOR_H
