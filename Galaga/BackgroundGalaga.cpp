//
// Created by ASUS on 11/23/2023.
//

#include "BackgroundGalaga.h"


BackgroundGalaga::BackgroundGalaga()
: BackgroundGalaga(Image::getImageBackground())
{

}

BackgroundGalaga::BackgroundGalaga(sf::Texture &image)
{
    sf::IntRect intRect;

    intRect.width = image.getSize().x;
    intRect.height = image.getSize().y;

    sprite.setTexture(image);
    sprite.setTextureRect(intRect);

    sf::Vector2u imageSize = image.getSize();

    float scaleX = (float) (800 / 1) / imageSize.x;
    float scaleY = (float) (700 / 1) / imageSize.y;

    sprite.setScale(scaleX, scaleY);

    sprite.setPosition({100, 100});
}

void BackgroundGalaga::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(sprite);
}

sf::Sprite &BackgroundGalaga::getSprite() {
    return sprite;
}

sf::FloatRect BackgroundGalaga::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

