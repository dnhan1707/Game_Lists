//
// Created by ASUS on 12/9/2023.
//

#ifndef SFML_PROJECT_CLOCK_H
#define SFML_PROJECT_CLOCK_H

#include "../Projects.h"
#include "clockHand.h"
#include "functions.h"

class Clock : public Projects
{

private:
    clockHand hourHand, minuteHand, secondHand;
    sf::CircleShape clockFace;
public:
    Clock();
    void run();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    std::string getName();
};


#endif //SFML_PROJECT_CLOCK_H
