//
// Created by ASUS on 11/14/2023.
//

#include "ButtonGalaga.h"

ButtonGalaga::ButtonGalaga()
: ButtonGalaga("0", {80, 80, 80}, {28, 28, 28})
{

}

ButtonGalaga::ButtonGalaga(const std::string &text, sf::Color color)
: ButtonGalaga(text, 30.f, color, sf::Color::White)
{

}

ButtonGalaga::ButtonGalaga(const std::string &text, sf::Color color, sf::Color textColor)
: ButtonGalaga(text, 30.f, color, textColor)
{

}

ButtonGalaga::ButtonGalaga(const std::string &text, float radius, sf::Color color, sf::Color textColor)
: ButtonGalaga(text, radius, FontGalaga::getFont(OPEN_SANS), color, textColor)
{

}

ButtonGalaga::ButtonGalaga(const std::string& text, float radius, sf::Font& font, sf::Color color, sf::Color textColor)
: defaultColor{color}, clickColor{212, 212, 210}
{
    setupCircle(radius);
    setUpText(text, font);
    setTextColor(textColor);

}

void ButtonGalaga::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!getState(HIDDEN))
    {
        states.transform = circleShape.getTransform();
        window.draw(circleShape);
        window.draw(text, states);
    }

}

void ButtonGalaga::setRadius(float radius) {
    this->circleShape.setRadius(radius);
    setCharacterSize();
    PositionGalaga::centerText(circleShape, text);
}

void ButtonGalaga::setFont(const sf::Font &font) {
    this->text.setFont(font);
}

void ButtonGalaga::setText(const std::string &text) {

    this->text.setString(text);
    PositionGalaga::centerText(circleShape, this->text);
}

std::string ButtonGalaga::getText() {
    return text.getString();
}

void ButtonGalaga::setClickColor(sf::Color color) {
    this->clickColor = color;
}

void ButtonGalaga::setDefaultColor(sf::Color color) {
    this->defaultColor = color;
}

void ButtonGalaga::setPosition(sf::Vector2f position)
{
    this->circleShape.setPosition(position);
}

void ButtonGalaga::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEventsGalaga::isCLicked(circleShape, window))
    {
        enableState(CLICK);
    }
    else {
        disableState(CLICK);
    }
}

sf::CircleShape& ButtonGalaga::getButton()
{
    return this->circleShape;
}

void ButtonGalaga::setupCircle(float radius)
{
    setRadius(radius);
    circleShape.setFillColor(defaultColor);
}

void ButtonGalaga::setUpText(const std::string &text, sf::Font &font)
{
    this->text.setFont(font);
    this->text.setString(text);
    setCharacterSize();
    PositionGalaga::centerText(circleShape, this->text);
}

void ButtonGalaga::update() {
    if(getState(CLICK))
    {
        circleShape.setFillColor(clickColor);
    }
    else circleShape.setFillColor(defaultColor);
}

void ButtonGalaga::setCharacterSize()
{
    float size = 15;
    this->text.setCharacterSize(size);
}

void ButtonGalaga::setTextColor(sf::Color color) {
    text.setFillColor(color);
}
