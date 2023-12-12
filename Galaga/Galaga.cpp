//
// Created by ASUS on 11/23/2023.
//

#include "Galaga.h"


Galaga::Galaga()
{
    PositionGalaga::alignCenter(background.getSprite(), fighterJet.getSprite(), 0, 200);

    display.setSize({80, 60});
    display.setCharacterSize(15);
    display.setColor(sf::Color{28, 28, 28});
    PositionGalaga::alignLeft(background.getSprite(), display);

    alienShip.addAlien();

    PositionGalaga::alignCenter(background.getSprite(), gameOver.getGameOverBackground(), 0, 0);
    gameOver.setPosition(gameOver.getGameOverBackground());
//    gameOver.setPosition(background);
}

void Galaga::draw(sf::RenderTarget &window, sf::RenderStates states) const
{

    if (fighterJet.getState(HIT))

    {
        window.draw(gameOver);
    }
    else
    {
        window.draw(background);
        window.draw(fighterJet);
        window.draw(alienShip);
        window.draw(gun);
        window.draw(display);
    }


}

void Galaga::run()
{
    if (!fighterJet.getState(HIT))
    {
        // Update game logic, e.g., movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            fighterJet.move({-5, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            fighterJet.move({0, -5});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            fighterJet.move({0, 5});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            fighterJet.move({5, 0});
        }
        alienShip.update();
        gun.shoot(fighterJet, background, alienShip);
        display.update();
    }


}

void Galaga::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

std::string Galaga::getName() {
    return "Galaga";
}

void Galaga::update() {

}
