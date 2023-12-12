//
// Created by ASUS on 11/14/2023.
//

#include "BackgroundCalculator.h"

BackgroundCalculator::BackgroundCalculator()
: BackgroundCalculator({400, 700})
{

}

BackgroundCalculator::BackgroundCalculator(sf::Vector2f size)
: sf::RectangleShape(size), StatesCalculator()
{

}

void BackgroundCalculator::eventHandler(sf::RenderWindow &window, sf::Event event) {

    if (MouseEvents::isHover(*this, window))
    {
        enableState(HOVERED);

    }
    else disableState(HOVERED);
}

void BackgroundCalculator::update() {
    if(getState(HOVERED))
    {
        setFillColor(sf::Color::Blue);
    }
    else setFillColor(sf::Color::White);

}

