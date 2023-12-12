//
// Created by ASUS on 12/9/2023.
//

#include "Clock.h"

Clock::Clock()
{
    //Time
    auto pacificTime = std::chrono::system_clock::now();
    auto timeInfo = std::chrono::system_clock::to_time_t(pacificTime);
    std::tm localTime = *std::localtime(&timeInfo);

    //Objects
    sf::CircleShape clockFace;

    //Clock object
    clockFace.setRadius(100);

    this->clockFace = clockFace;

    //Coordinate
    float xCenter, yCenter;
    sf::FloatRect bounds = clockFace.getGlobalBounds();
    xCenter = bounds.left + bounds.width / 2;
    yCenter = bounds.top + bounds.height / 2;

    //Create Hand
    clockHand hourHand
            (
                    1.f / 3600,
                    {clockFace.getRadius() * .4f, 7.f},
                    {xCenter, yCenter},
                    sf::Color::Blue,
                    static_cast<float>(localTime.tm_hour),
                    30.f
            );
    this->hourHand = hourHand;

    clockHand minuteHand
            (
                    1.f / 60,
                    {clockFace.getRadius() * .5f, 7.f},
                    {xCenter, yCenter},
                    sf::Color::Red,
                    static_cast<float>(localTime.tm_min),
                    6.f
            );
    this->minuteHand = minuteHand;

    clockHand secondHand
            (
                    1.f,
                    {clockFace.getRadius() * .9f, 7.f},
                    {xCenter, yCenter},
                    sf::Color::Black,
                    static_cast<float>(localTime.tm_sec),
                    6.f
            );
    this->secondHand = secondHand;

}

void Clock::run()
{
    hourHand.rotate();
    minuteHand.rotate();
    secondHand.rotate();
}

void Clock::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(clockFace);
    window.draw(secondHand);
    window.draw(minuteHand);
    window.draw(hourHand);
}

void Clock::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Clock::update()
{

}

std::string Clock::getName() {
    return "Clock";
}
