//
// Created by ASUS on 11/2/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_HANDCONTAINER_H
#define ANALOG_DIGITAL_CLOCK_HANDCONTAINER_H

#include "CardGraphic.h"

class HandContainer : public sf::Drawable
{
public:
    void addHand(const CardGraphic& cardGraphic);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

private:
    std::vector<CardGraphic> cardGraphics;
};


#endif //ANALOG_DIGITAL_CLOCK_HANDCONTAINER_H
