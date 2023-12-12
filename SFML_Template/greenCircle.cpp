//
// Created by ASUS on 12/9/2023.
//

#include "greenCircle.h"

void greenCircle::run() {

}

void greenCircle::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(circle);
}

void greenCircle::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void greenCircle::update() {

}

std::string greenCircle::getName() {
    return "Green Circle";
}

greenCircle::greenCircle() {
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Green);
}
