//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_POSITIONGALAGA_H
#define SFML_PROJECT_POSITIONGALAGA_H

#include "SFML/Graphics.hpp"
#include "iostream"
#include <cmath>

class PositionGalaga
{
public:
    template<typename T, typename S>
    static void left(const S& constObject, T& object, float spacing = 0); //position object to the left of constObject

    template<typename T, typename S>
    static void right(const S& constObject, T& object, float spacing = 2);

    template<typename T, typename S>
    static void above(const S& constObject, T& object, float spacing = 0);

    template<typename T, typename S>
    static void aboveAndMiddle(const T& constObject, S& object, float spacing = 0);

    template<typename T, typename S>
    static void below(const S& constObject, T& object, float spacing = 5);

    template<typename T>
    static void centerText(const T &obj, sf::Text &text, float spacing = 0);

    template<typename T, typename S>
    static void center(const T &constObj, S &obj, float spacing = 0);

    template<typename T, typename S>
    static void alignCenterAndInside(const T &constObj, S &obj, float spacing);

    template<typename T, typename S>
    static void alignCenter(const T &constObj, S &obj, float margin_x, float margin_y);

    template<typename T, typename S>
    static void alignLeft(const T &constObj, S &obj, float margin_x = 0, float margin_y = 0);

    template<typename T, typename S>
    static void belowAndAlignCenterForCircle(const T &constObj, S &obj, float spacing = 5);

    template<typename T, typename S>
    static void belowAndAlignCenterForCircleInObject(const T &constObj, S &obj, float spacing = 5);

    template<typename T, typename S>
    static void centerWithWindow(const T &constObj, S &obj, float spacing = 5);

};


#include "PositionGalaga.cpp"
#endif //SFML_PROJECT_POSITIONGALAGA_H
