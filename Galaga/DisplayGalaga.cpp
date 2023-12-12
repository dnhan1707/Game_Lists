//
// Created by ASUS on 11/14/2023.
//

#include "DisplayGalaga.h"

DisplayGalaga::DisplayGalaga() //TODO after Fonts class is created
: DisplayGalaga({200, 200}, FontGalaga::getFont(OPEN_SANS), 24)
{

}

DisplayGalaga::DisplayGalaga(sf::Vector2f size, sf::Font& font, unsigned int characterSize)
: DisplayGalaga(size, font, characterSize, sf::Color::Black, {0, 0 }, 9, true)  // Enable time tracking
{
}


DisplayGalaga::DisplayGalaga(sf::Vector2f size, sf::Font& font, unsigned int characterSize, sf::Color color, sf::Vector2f position, int limit, bool trackTime)
{
    setSize(size);
    setFont(font);
    setCharacterSize(characterSize);
    setColor(color);
    setPosition(position);
}

void DisplayGalaga::show() {

    disableState(HIDDEN);
}

void DisplayGalaga::clear() {
    text.setString("");
}

void DisplayGalaga::setText(const std::string &text) {
    PositionGalaga::centerText(box, this->text);

    this->text.setString(text);
}

std::string DisplayGalaga::getText() {
    return text.getString();

}

void DisplayGalaga::setCharacterLimit(int limits) {
    this->limit = limits;
}

void DisplayGalaga::setColor(sf::Color color) {
    this->box.setFillColor(color);
}

void DisplayGalaga::setFont(const sf::Font &font) {
    this->text.setFont(font);
}

void DisplayGalaga::setSize(sf::Vector2f size) {
    this->box.setSize(size);
}

void DisplayGalaga::setPosition(sf::Vector2f position) {
    this->box.setPosition(position);
}

void DisplayGalaga::setCharacterSize(unsigned int size) {
    this->text.setCharacterSize(size);
}

void DisplayGalaga::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(box);
    window.draw(text);
}

sf::RectangleShape &DisplayGalaga::getDisplayBox() {
    return this->box;
}

void DisplayGalaga::setTextPosition(sf::Vector2f position)
{
    text.setPosition(position);
}

sf::Text& DisplayGalaga::getTextObject()
{
    return text;
}


void DisplayGalaga::update() {
    // Update the text with the elapsed time
    setText(getElapsedTimeAsString());
}


std::string DisplayGalaga::getElapsedTimeAsString() {
    // Get elapsed time in seconds
    float elapsedSeconds = clock.getElapsedTime().asSeconds();

    // Format elapsed time as a string (minutes:seconds)
    int minutes = static_cast<int>(elapsedSeconds) / 60;
    int seconds = static_cast<int>(elapsedSeconds) % 60;

    return "Time: " + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
}