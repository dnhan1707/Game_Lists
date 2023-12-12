//
// Created by ASUS on 12/9/2023.
//

#ifndef SFML_PROJECT_PORTFOLIO_H
#define SFML_PROJECT_PORTFOLIO_H

#include "Runable.h"
#include "Nameable.h"
#include "vector"
#include "iostream"
#include "ButtonPortfolio.h"
#include "Projects.h"
#include "MouseEventsPortfolio.h"
#include "DisplayProjectName.h"
#include "StateEnumPortfolio.h"
#include "PositionPortfolio.h"

class Portfolio
{
private:
    ButtonPortfolio left, right;
    bool buttonLeft = false, buttonRight = false;
    std::vector<Projects*> projects;
    std::vector<Projects*>::iterator iter;
//    sf::RectangleShape Border;
    DisplayProjectName projectName;
public:
    Portfolio();
    void run();
    void addProject(Projects& project);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_PORTFOLIO_H
