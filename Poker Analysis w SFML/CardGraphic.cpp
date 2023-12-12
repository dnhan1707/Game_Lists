//
// Created by ASUS on 10/19/2023.
//


#include "CardGraphic.h"



CardGraphic::CardGraphic()
{

}


CardGraphic::CardGraphic(const Card& card, sf::Vector2f position)
: CardGraphic(card.getRank(), card.getSuit(), position)
{

}

CardGraphic::CardGraphic(Rank rank, Suit suit, sf::Vector2f position)
:CardGraphic(ImagePoker::getImage(), rank, suit, position)  //we do not use object to use getImage() bc getImage() func is static
{

}


CardGraphic::CardGraphic(sf::Texture& image, Rank rank, Suit suit, sf::Vector2f position)
{
    sf::IntRect intRect;

    intRect.width = image.getSize().x / 13;
    intRect.height = image.getSize().y / 4;

    intRect.left = intRect.width * rank;
    intRect.top = intRect.height * suit;

    sprite.setTexture(image);
    sprite.setTextureRect(intRect);

    sprite.setPosition(position);
}


void CardGraphic::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(sprite);
}

