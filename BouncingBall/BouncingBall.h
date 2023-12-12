//
// Created by ASUS on 12/11/2023.
//

#ifndef SFML_PROJECT_BOUNCINGBALL_H
#define SFML_PROJECT_BOUNCINGBALL_H

#include "../Projects.h"
#include "Ball.h"

class BouncingBall : public Projects
{
private:
    Ball ball;
public:
    BouncingBall();
    void run();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    std::string getName();
};


#endif //SFML_PROJECT_BOUNCINGBALL_H
