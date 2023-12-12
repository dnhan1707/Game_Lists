//
// Created by ASUS on 12/9/2023.
//

#include "ButtonPortfolio.h"

ButtonPortfolio::ButtonPortfolio()
        :ButtonPortfolio("0", {80,80,80}, {28, 28, 28})
{

}

ButtonPortfolio::ButtonPortfolio(const std::string &text, sf::Color color)
        :ButtonPortfolio(text, 30.f, color, sf::Color::White)
{

}

ButtonPortfolio::ButtonPortfolio(const std::string &text, sf::Color color, sf::Color textColor)
        :ButtonPortfolio(text, 30.f, color, textColor)
{

}

ButtonPortfolio::ButtonPortfolio(const std::string &text, float radius, sf::Color color, sf::Color textColor)
        :ButtonPortfolio(text, radius, FontPortfolio::getFont(OPEN_SANS), color, textColor)
{

}

ButtonPortfolio::ButtonPortfolio(const std::string& text, float radius, sf::Font& font, sf::Color color, sf::Color textColor)
        : defaultColor{color}, clickColor{212, 212, 210}
{
    setupCircle(radius);
    setUpText(text, font);
    setTextColor(textColor);

}

void ButtonPortfolio::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!getState(HIDDEN))
    {
        states.transform = circleShape.getTransform();
        window.draw(circleShape);
        window.draw(text, states);
    }

}

void ButtonPortfolio::setRadius(float radius) {
    this->circleShape.setRadius(radius);
    setCharacterSize();
    PositionPortfolio::centerText(circleShape, text);
}

void ButtonPortfolio::setFont(const sf::Font &font) {
    this->text.setFont(font);
}

void ButtonPortfolio::setText(const std::string &text) {

    this->text.setString(text);
    PositionPortfolio::centerText(circleShape, this->text);
}

std::string ButtonPortfolio::getText() {
    return text.getString();
}

void ButtonPortfolio::setClickColor(sf::Color color) {
    this->clickColor = color;
}

void ButtonPortfolio::setDefaultColor(sf::Color color) {
    this->defaultColor = color;
}

void ButtonPortfolio::setPosition(sf::Vector2f position)
{
    this->circleShape.setPosition(position);
}

void ButtonPortfolio::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEventsPortfolio::isClicked(circleShape, window))
    {
        enableState(CLICK);
    }
    else {
        disableState(CLICK);
    }
}

sf::CircleShape& ButtonPortfolio::getButton()
{
    return this->circleShape;
}

void ButtonPortfolio::setupCircle(float radius)
{
    setRadius(radius);
    circleShape.setFillColor(defaultColor);
}

void ButtonPortfolio::setUpText(const std::string &text, sf::Font &font)
{
    this->text.setFont(font);
    this->text.setString(text);
    setCharacterSize();
    PositionPortfolio::centerText(circleShape, this->text);
}

void ButtonPortfolio::update() {
    if(getState(CLICK))
    {
        circleShape.setFillColor(clickColor);
    }
    else circleShape.setFillColor(defaultColor);
}

void ButtonPortfolio::setCharacterSize()
{
    float size = 15;
    this->text.setCharacterSize(size);
}

void ButtonPortfolio::setTextColor(sf::Color color) {
    text.setFillColor(color);
}
