//
// Created by ASUS on 11/14/2023.
//

#include "Font.h"

std::string Font::getPath(FontEnumPortfolio font) {
    switch (font) {
        case ARIAL:
            return "FontsPortfolio/arial.ttf";

        case STARMONK:
            return "FontsPortfolio/STARMONK.TTF";

        case OPEN_SANS:
            return "FontsPortfolio/OpenSans-Bold.ttf";
        default:
            return "Can't load font";
    }
}

void Font::loadfont(FontEnumPortfolio font)
{
    fonts[font].loadFromFile(getPath(font));
}

sf::Font& Font::getFont(FontEnumPortfolio font)
{
    loadfont(font);
    return fonts[font];
}
