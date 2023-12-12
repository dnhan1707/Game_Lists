//
// Created by ASUS on 11/2/2023.
//

#include "HandContainer.h"

void HandContainer::addHand(const CardGraphic& cardGraphic) {
    cardGraphics.push_back(cardGraphic);
}

void HandContainer::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    for (const CardGraphic& cardGraphic : cardGraphics) {
        window.draw(cardGraphic);
    }
}