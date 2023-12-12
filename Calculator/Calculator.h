//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_CALCULATOR_H
#define SFML_PROJECT_CALCULATOR_H

#include "SFML/Graphics.hpp"
#include "BackgroundCalculator.h"
#include "RPN.h"
#include "DisplayCalculator.h"
#include "ButtonCalculator.h"
#include "PositionCalculator.h"
#include "vector"
#include "../Projects.h"
#include "string"

class Calculator : public Projects
{
private:
    BackgroundCalculator background;
    DisplayCalculator display;

    std::vector<ButtonCalculator> buttons;
    std::string expression;
public:
    Calculator();
    void run();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    std::string getName();

    void setExpression(const std::string& character);
    void resetExpression();
};


#endif //SFML_PROJECT_CALCULATOR_H
