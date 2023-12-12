//
// Created by ASUS on 10/19/2023.
//

#ifndef FRIEND_FUNCTION_CARDGRAPHIC_H
#define FRIEND_FUNCTION_CARDGRAPHIC_H


#include <SFML/Graphics.hpp>
#include "Card.h"
#include "ImagePoker.h"

class CardGraphic : public sf::Drawable
{
public:
    CardGraphic();
    CardGraphic(const Card& card, sf::Vector2f position);
    CardGraphic(Rank rank, Suit suit, sf::Vector2f position);
    CardGraphic(sf::Texture& image, Rank rank, Suit suit, sf::Vector2f position);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:
    std::vector<sf::Vector2f> cardPositions;
    sf::Sprite sprite;
};


#endif //FRIEND_FUNCTION_CARDGRAPHIC_H
