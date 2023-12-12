//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_POSITION_CPP
#define SFML_PROJECT_POSITION_CPP

#include "PositionPortfolio.h"

template<typename T, typename S>
void PositionPortfolio::left(const S& constObject, T& object, float spacing)
{
    sf::FloatRect constBounce = constObject.getGlobalBounds();
    sf::FloatRect objectBounce = object.getGlobalBounds();

    float x = constBounce.left - spacing - objectBounce.width;
    float y = constBounce.top;

    object.setPosition({x, y});
}

template<typename T, typename S>
void PositionPortfolio::right(const S &constObject, T &object, float spacing) {
    sf::FloatRect constBounce = constObject.getGlobalBounds();

    float x = constBounce.left + spacing + constBounce.width;
    float y = constBounce.top;

    object.setPosition({x, y});
}

template<typename T, typename S>
void PositionPortfolio::above(const S &constObject, T &object, float spacing) {
    sf::FloatRect constBounce = constObject.getGlobalBounds();
    sf::FloatRect objectBounce = object.getGlobalBounds();

    float x = constBounce.left;
    float y = constBounce.top - spacing - objectBounce.height;

    object.setPosition({x, y});
}


template<typename T, typename S>
void PositionPortfolio::aboveAndMiddle(const T &constObject, S &object, float spacing) {
    sf::FloatRect cb = constObject.getGlobalBounds();
    sf::FloatRect ob = object.getGlobalBounds();

    float xDif = cb.width - ob.width;
    float x = cb.left + (xDif/2);

    float y = cb.top - spacing - ob.height;

    object.setPosition({x, y});
}


template<typename T, typename S>
void PositionPortfolio::below(const S &constObject, T &object, float spacing) {
    sf::FloatRect constBounce = constObject.getGlobalBounds();
    sf::FloatRect objectBounce = object.getGlobalBounds();

    float x = constBounce.left;
    float y = constBounce.top + constBounce.height + spacing;

    object.setPosition({x, y});
}

template<typename T>
void PositionPortfolio::centerText(const T &obj, sf::Text &text, float spacing)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});

}

template<typename T, typename S>
void PositionPortfolio::center(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    float xDif = cb.width - ob.width;
    float yDif = cb.height - ob.height;
    float x = cb.left + (xDif/2);
    float y = cb.top + (yDif/2);
    obj.setPosition({x,y});
}

template<typename T, typename S>
void PositionPortfolio::alignCenterAndInside(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    float x = cb.left;
    float y = cb.top;
    obj.setPosition({x,y});
}

template<typename T, typename S>
void PositionPortfolio::alignCenter(const T &constObj, S &obj, float margin_x, float margin_y)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    float xDif = cb.width - ob.width;
    float x = cb.left + (xDif/2) + margin_x;

    float yDif = cb.height - ob.height;
    float y = cb.top + (yDif/2) + margin_y;
    obj.setPosition({x, y});
}



template<typename T, typename S>
void PositionPortfolio::alignLeft(const T &constObj, S &obj, float margin_x, float margin_y)
{
    sf::FloatRect cb = constObj.getGlobalBounds();

    float x = cb.left + margin_x;
    float y = cb.top + margin_y;

    obj.setPosition({x, y});
}

template<typename T, typename S>
void PositionPortfolio::belowAndAlignCenterForCircle(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    float x = ((cb.width / 2) - (obj.getRadius() * 4)) + cb.left;
    obj.setPosition({x, cb.height + spacing});
}

template<typename T, typename S>
void PositionPortfolio::belowAndAlignCenterForCircleInObject(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    float x = ((cb.width / 2) - (obj.getRadius() * 4)) + cb.left;
    float y = cb.top + cb.height + spacing;
    obj.setPosition({x, y});
}

template<typename T, typename S>
void PositionPortfolio::centerWithWindow(const T &constObj, S &obj, float spacing)
{
    sf::Vector2u cb = constObj.getSize();
    sf::FloatRect ob = obj.getGlobalBounds();
    float x = cb.x/2 - ob.width/2;
    float y = cb.y/2 - ob.height/2;

    obj.setPosition({x,y});
}

#endif