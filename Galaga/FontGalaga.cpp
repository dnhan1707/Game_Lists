//
// Created by ASUS on 11/14/2023.
//

#include "FontGalaga.h"

std::string FontGalaga::getPath(FontEnumPortfolio font) {
    switch (font) {
        case ARIAL:
            return "FontsPortfolio/arial.ttf";

        case STARMONK:
            return "FontsPortfolio/STARMONK.TTF";

        case OPEN_SANS:
            return "FontsPortfolio/OpenSans-Bold.ttf";
    }
}

void FontGalaga::loadfont(FontEnumPortfolio font)
{
    fonts[font].loadFromFile(getPath(font));
}

sf::Font& FontGalaga::getFont(FontEnumPortfolio font)
{
    loadfont(font);
    return fonts[font];
}
