//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_BUTTONGALAGA_H
#define SFML_PROJECT_BUTTONGALAGA_H
#include "SFML/Graphics.hpp"
#include "MouseEventsGalaga.h"
#include "FontGalaga.h"
#include "PositionGalaga.h"
#include "StatesGalaga.h"
#include "DisplayGalaga.h"

class ButtonGalaga : public sf::Drawable, public StatesGalaga
{
private:
    sf::Text text;
    sf::CircleShape circleShape;
    sf::Color defaultColor, clickColor;

    DisplayGalaga display;


public:
    ButtonGalaga();
    ButtonGalaga(const std::string& text, sf::Color color);
    ButtonGalaga(const std::string& text, sf::Color color, sf::Color textColor);

    ButtonGalaga(const std::string& text, float radius, sf::Color color, sf::Color textColor);
    ButtonGalaga(const std::string& text, float radius, sf::Font& font, sf::Color color, sf::Color textColor);
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


#endif //SFML_PROJECT_BUTTONGALAGA_H
