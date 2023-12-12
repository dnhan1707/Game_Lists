//
// Created by ASUS on 11/14/2023.
//

#include "DisplayCalculator.h"

DisplayCalculator::DisplayCalculator() //TODO after Fonts class is created
: DisplayCalculator({200, 200}, Font::getFont(OPEN_SANS), 24)
{

}

DisplayCalculator::DisplayCalculator(sf::Vector2f size, sf::Font& font, unsigned int characterSize)
: DisplayCalculator(size, font, characterSize, sf::Color::Black, {0, 0}, 9)
{
}


DisplayCalculator::DisplayCalculator(sf::Vector2f size, sf::Font& font, unsigned int characterSize, sf::Color color, sf::Vector2f position, int limit)
{
    setSize(size);
    setFont(font);
    setCharacterSize(characterSize);
    setColor(color);
    setPosition(position);
    setCharacterLimit(limit);
}

void DisplayCalculator::show() {

    disableState(HIDDEN);
}

void DisplayCalculator::clear() {
    text.setString("");
}

void DisplayCalculator::setText(const std::string &text) {
    this->text.setString(text);
}

std::string DisplayCalculator::getText() {
    return text.getString();
}

void DisplayCalculator::setCharacterLimit(int limits) {
    this->limit = limits;
}

void DisplayCalculator::setColor(sf::Color color) {
    this->box.setFillColor(color);
}

void DisplayCalculator::setFont(const sf::Font &font) {
    this->text.setFont(font);
}

void DisplayCalculator::setSize(sf::Vector2f size) {
    this->box.setSize(size);
}

void DisplayCalculator::setPosition(sf::Vector2f position) {
    this->box.setPosition(position);
}

void DisplayCalculator::setCharacterSize(unsigned int size) {
    this->text.setCharacterSize(size);
}

void DisplayCalculator::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    if (!getState(HIDDEN))
    {
        window.draw(box);
        window.draw(text);
    }

}

sf::RectangleShape &DisplayCalculator::getDisplayBox() {
    return this->box;
}

void DisplayCalculator::update() {
    if(getState(CLICK))
    {
        text.setFillColor(sf::Color::White);
    }
}


void DisplayCalculator::setTextPosition(sf::Vector2f position)
{
    text.setPosition(position);
}

sf::Text& DisplayCalculator::getTextObject()
{
    return text;
}
