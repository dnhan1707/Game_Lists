//
// Created by ASUS on 11/23/2023.
//

#ifndef SFML_PROJECT_GALAGA_H
#define SFML_PROJECT_GALAGA_H

#include "SFML/Graphics.hpp"
#include "BackgroundGalaga.h"
#include "FighterJet.h"
#include "PositionGalaga.h"
#include "Rocket.h"
#include "Gun.h"
#include "vector"
#include "AlienShip.h"
#include "HitBox.h"
#include "DisplayGalaga.h"
#include "GameOver.h"
#include "../Projects.h"

class Galaga : public Projects, public StatesGalaga
{
private:
    FighterJet fighterJet;
    BackgroundGalaga background;
    DisplayGalaga display;

    sf::Clock clock;

    AlienShip alienShip;
    Gun gun;
    GameOver gameOver;

    bool isOver = false;
public:
    Galaga();

    void run();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    std::string getName();
};


#endif //SFML_PROJECT_GALAGA_H
