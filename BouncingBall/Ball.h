//
// Created by ASUS on 10/9/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_BALL_H
#define ANALOG_DIGITAL_CLOCK_BALL_H

#include "iostream"
#include <cmath>
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable
{

public:
    void setText(std::string string);
    Ball();
    void setBallStyle(sf::Color color);
    void bounce();
    void setBounds();
    void setRadius(float radius);
    void setStartPoints(float &ball_x, float &ball_y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void centerText(const sf::CircleShape &obj, sf::Text &text);
private:
    sf::CircleShape circle;
    float bounce_top, bounce_bottom, bounce_left, bounce_right;
    float start_x, start_y;
    bool first_move = true;
    sf::Color red, green, blue, yellow, purple, orange, brown, black;
    std::string numbers[8] = {"1", "2", "3", "4", "5", "6", "7", "8"};
    sf::Color all_color[8] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color(255, 0, 255), sf::Color(247, 147, 30), sf::Color(162, 64, 44), sf::Color::Black};
    sf::Text text;
    sf::Font font;
    sf::Window window;
};


#endif //ANALOG_DIGITAL_CLOCK_BALL_H
