//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_BACKGROUNDCALCULATOR_H
#define SFML_PROJECT_BACKGROUNDCALCULATOR_H

#include "SFML/Graphics.hpp"
#include "StatesCalculator.h"
#include "MouseEvents.h"
#include "DisplayCalculator.h"

class BackgroundCalculator : public sf::RectangleShape, public StatesCalculator
{
public:
    BackgroundCalculator();
    BackgroundCalculator(sf::Vector2f size);

    void eventHandler(sf::RenderWindow& window, sf::Event event);

    void update();
private:

};


#endif //SFML_PROJECT_BACKGROUNDCALCULATOR_H
