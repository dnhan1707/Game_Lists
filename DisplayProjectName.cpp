//
// Created by ASUS on 12/9/2023.
//

#include "DisplayProjectName.h"
DisplayProjectName::DisplayProjectName() //TODO after FontsPortfolio class is created
        :DisplayProjectName({200, 200}, FontPortfolio::getFont(OPEN_SANS), 24)
{

}

DisplayProjectName::DisplayProjectName(sf::Vector2f size, sf::Font& font, unsigned int characterSize)
        : DisplayProjectName(size, font, characterSize, sf::Color::Black, { 0, 0 }, 9, true)  // Enable time tracking
{
}


DisplayProjectName::DisplayProjectName(sf::Vector2f size, sf::Font& font, unsigned int characterSize, sf::Color color, sf::Vector2f position, int limit, bool trackTime)
{
    setSize(size);
    setFont(font);
    setCharacterSize(characterSize);
    setColor(color);
    setPosition(position);
}

void DisplayProjectName::show() {

    disableState(HIDDEN);
}

void DisplayProjectName::clear() {
    text.setString("");
}

void DisplayProjectName::setText(const std::string &text) {
    PositionPortfolio::centerText(box, this->text);
    this->text.setString(text);
}

std::string DisplayProjectName::getText() {
    return text.getString();

}

void DisplayProjectName::setCharacterLimit(int limits) {
    this->limit = limits;
}

void DisplayProjectName::setColor(sf::Color color) {
    this->box.setFillColor(color);
}

void DisplayProjectName::setFont(const sf::Font &font) {
    this->text.setFont(font);
}

void DisplayProjectName::setSize(sf::Vector2f size) {
    this->box.setSize(size);
}

void DisplayProjectName::setPosition(sf::Vector2f position) {
    this->box.setPosition(position);
}

void DisplayProjectName::setCharacterSize(unsigned int size) {
    this->text.setCharacterSize(size);
}

void DisplayProjectName::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(box);
    window.draw(text);
}

sf::RectangleShape &DisplayProjectName::getDisplayBox() {
    return this->box;
}

void DisplayProjectName::setTextPosition(sf::Vector2f position)
{
    text.setPosition(position);
}

sf::Text& DisplayProjectName::getTextObject()
{
    return text;
}
