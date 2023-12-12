//
// Created by ASUS on 12/9/2023.
//

#ifndef SFML_PROJECT_GREENCIRCLE_H
#define SFML_PROJECT_GREENCIRCLE_H

#include "SFML/Graphics.hpp"
#include "../Projects.h"


class greenCircle : public Projects
{
private:
    sf::CircleShape circle;

public:
    greenCircle();
    void run();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    std::string getName();

};


#endif //SFML_PROJECT_GREENCIRCLE_H
