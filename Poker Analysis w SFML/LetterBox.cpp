#include "LetterBox.h"

LetterBox::LetterBox()
        : LetterBox("B", {0, 0})
{
}

LetterBox::LetterBox(sf::Vector2f position)
        : LetterBox("B", {50, 50}, position)
{
}

LetterBox::LetterBox(std::string letter, sf::Vector2f position)
        : LetterBox(letter, {50, 50}, position)
{
}

LetterBox::LetterBox(std::string letter, sf::Vector2f size, sf::Vector2f position)
        : LetterBox(letter, {200, 50}, 24, sf::Color(255, 193, 203), sf::Color::Black, position)
{
}

LetterBox::LetterBox(std::string letter, sf::Vector2f size, unsigned int characterSize,
                     sf::Color boxColor, sf::Color textColor, sf::Vector2f position)
{
    box.setSize(size);
    box.setFillColor(boxColor);

    if (!font.loadFromFile("FontsPortfolio/arial.ttf")) {
        exit(28); // You might want to handle the error more gracefully.
    }

    this->letter.setFont(font);
    this->letter.setCharacterSize(characterSize);
    this->letter.setFillColor(textColor);
    box.setPosition(position);
    setLetter(letter);
}

void LetterBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    states.transform = box.getTransform();
    window.draw(box);
    window.draw(letter, states);
}

std::string LetterBox::getLetter()
{
    return letter.getString();
}

void LetterBox::setLetter(std::string letter)
{
    this->letter.setString(letter);
}

void LetterBox::move(sf::Vector2f velocity)
{
    box.move(velocity);
}
