//
// Created by ASUS on 11/23/2023.
//

#ifndef SFML_PROJECT_BACKGROUNDGALAGA_H
#define SFML_PROJECT_BACKGROUNDGALAGA_H

#include "SFML/Graphics.hpp"
#include "Image.h"
#include "PositionGalaga.h"

class BackgroundGalaga : public sf::Drawable
{
public:
    BackgroundGalaga();
    BackgroundGalaga(sf::Texture& image);

    sf::Sprite& getSprite();

    sf::FloatRect getGlobalBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:

    sf::Sprite sprite;
};


#endif //SFML_PROJECT_BACKGROUNDGALAGA_H
