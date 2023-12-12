//
// Created by ASUS on 11/16/2023.
//

#ifndef SFML_PROJECT_MOUSEEVENTSGALAGA_H
#define SFML_PROJECT_MOUSEEVENTSGALAGA_H

#include "SFML/Graphics.hpp"
namespace MouseEventsGalaga
{
    template<typename T>
    bool isHover(const T& obj, sf::RenderWindow& window);

    template<typename T>
    bool isCLicked(const T& obj, sf::RenderWindow& window);

} // MouseEvents

#include "MouseEventsGalaga.cpp"
#endif //SFML_PROJECT_MOUSEEVENTSGALAGA_H
