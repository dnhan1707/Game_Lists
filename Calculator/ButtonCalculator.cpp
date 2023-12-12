//
// Created by ASUS on 11/14/2023.
//

#include "ButtonCalculator.h"

ButtonCalculator::ButtonCalculator()
: ButtonCalculator("0", {80, 80, 80}, {28, 28, 28})
{

}

ButtonCalculator::ButtonCalculator(const std::string &text, sf::Color color)
: ButtonCalculator(text, 30.f, color, sf::Color::White)
{

}

ButtonCalculator::ButtonCalculator(const std::string &text, sf::Color color, sf::Color textColor)
: ButtonCalculator(text, 30.f, color, textColor)
{

}

ButtonCalculator::ButtonCalculator(const std::string &text, float radius, sf::Color color, sf::Color textColor)
: ButtonCalculator(text, radius, Font::getFont(OPEN_SANS), color, textColor)
{

}

ButtonCalculator::ButtonCalculator(const std::string& text, float radius, sf::Font& font, sf::Color color, sf::Color textColor)
: defaultColor{color}, clickColor{212, 212, 210}
{
    setupCircle(radius);
    setUpText(text, font);
    setTextColor(textColor);

}

void ButtonCalculator::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!getState(HIDDEN))
    {
        states.transform = circleShape.getTransform();
        window.draw(circleShape);
        window.draw(text, states);
    }

}

void ButtonCalculator::setRadius(float radius) {
    this->circleShape.setRadius(radius);
    setCharacterSize();
    PositionCalculator::centerText(circleShape, text);
}

void ButtonCalculator::setFont(const sf::Font &font) {
    this->text.setFont(font);
}

void ButtonCalculator::setText(const std::string &text) {

    this->text.setString(text);
    PositionCalculator::centerText(circleShape, this->text);
}

std::string ButtonCalculator::getText() {
    return text.getString();
}

void ButtonCalculator::setClickColor(sf::Color color) {
    this->clickColor = color;
}

void ButtonCalculator::setDefaultColor(sf::Color color) {
    this->defaultColor = color;
}

void ButtonCalculator::setPosition(sf::Vector2f position)
{
    this->circleShape.setPosition(position);
}

void ButtonCalculator::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isCLicked(circleShape, window))
    {
        enableState(CLICK);
    }
    else {
        disableState(CLICK);
    }
}

sf::CircleShape& ButtonCalculator::getButton()
{
    return this->circleShape;
}

void ButtonCalculator::setupCircle(float radius)
{
    setRadius(radius);
    circleShape.setFillColor(defaultColor);
}

void ButtonCalculator::setUpText(const std::string &text, sf::Font &font)
{
    this->text.setFont(font);
    this->text.setString(text);
    setCharacterSize();
    PositionCalculator::centerText(circleShape, this->text);
}

void ButtonCalculator::update() {
    if(getState(CLICK))
    {
        circleShape.setFillColor(clickColor);
    }
    else circleShape.setFillColor(defaultColor);
}

void ButtonCalculator::setCharacterSize() {
    float size = (2.f/3) * (2 * circleShape.getRadius());
    this->text.setCharacterSize(size);
}

void ButtonCalculator::setTextColor(sf::Color color) {
    text.setFillColor(color);
}
