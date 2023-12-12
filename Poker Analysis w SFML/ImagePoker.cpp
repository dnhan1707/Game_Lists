//
// Created by ASUS on 10/19/2023.
//

#include "ImagePoker.h"

sf::Texture ImagePoker::texture; // actually create texture

void ImagePoker::loadTexture()
{
    texture.loadFromFile("Poker Analysis w SFML/Deck.png");
}

sf::Texture& ImagePoker::getImage()
{
    loadTexture();
    return texture;
}