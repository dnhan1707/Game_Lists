//
// Created by ASUS on 11/2/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_LETTERBOX_H
#define ANALOG_DIGITAL_CLOCK_LETTERBOX_H

#include <SFML/Graphics.hpp>
#include <string>

class LetterBox  : public sf::Drawable
{
private:
    sf::RectangleShape box;
    sf::Text letter;
    sf::Font font;
public:
    LetterBox();
    LetterBox(sf::Vector2f position);
    LetterBox(std::string letter, sf::Vector2f position);
    LetterBox(std::string letter, sf::Vector2f size, sf::Vector2f position);
    LetterBox(std::string letter, sf::Vector2f size, unsigned int characaterSize,
              sf::Color boxColor, sf::Color textColor,
              sf::Vector2f position);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    std::string getLetter();
    void setLetter(std::string letter);
    void move(sf::Vector2f velocity);


};


#endif //ANALOG_DIGITAL_CLOCK_LETTERBOX_H
