//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_FONTPORFOLIO_H
#define SFML_PROJECT_FONTPORFOLIO_H

#include "SFML/Graphics.hpp"
#include <map>
#include "FontEnumPortfolio.h"

class FontPortfolio : public sf::Drawable
{
private:

    inline static std::map<FontEnumPortfolio, sf::Font > fonts;
    static std::string getPath(FontEnumPortfolio font);
    static void loadfont(FontEnumPortfolio font);

public:
    static sf::Font& getFont(FontEnumPortfolio fontEnum);
};


#endif //SFML_PROJECT_FONTPORFOLIO_H
