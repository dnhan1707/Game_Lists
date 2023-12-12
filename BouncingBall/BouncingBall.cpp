//
// Created by ASUS on 12/11/2023.
//

#include "BouncingBall.h"

BouncingBall::BouncingBall()
{
    ball.setRadius(20.f);
    ball.setBounds();
}

void BouncingBall::run() {
    ball.bounce();
}

void BouncingBall::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(ball);
}

void BouncingBall::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void BouncingBall::update() {

}

std::string BouncingBall::getName() {
    return "Bouncing Ball";
}

