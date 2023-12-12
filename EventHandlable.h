//
// Created by ASUS on 12/9/2023.
//

#ifndef SFML_PROJECT_EVENTHANDLABLE_H
#define SFML_PROJECT_EVENTHANDLABLE_H

#include "SFML/Graphics.hpp"

class EventHandlable
{
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;

};


#endif //SFML_PROJECT_EVENTHANDLABLE_H
