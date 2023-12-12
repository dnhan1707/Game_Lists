//
// Created by ASUS on 10/9/2023.
//

#include "Ball.h"


Ball::Ball()
{

}


void Ball::setStartPoints(float &ball_x, float &ball_y)
{
    this->start_x = ball_x;
    this->start_y = ball_y;
}


void Ball:: bounce()
{
    int rand_num = rand() % 8;

    if (first_move)
    {
        start_x = 5;
        start_y = 2;
        setText(numbers[rand_num]);
        circle.move(start_x, start_y);
        setBallStyle(all_color[5]);
        first_move = false;
    }


    else if (circle.getPosition().x >= bounce_right - (circle.getRadius()*2) || circle.getGlobalBounds().left <= bounce_left)
    {
        start_x *= -1;
//        setText(numbers[rand_num]);
        setBallStyle(all_color[rand_num]);
    }
    else if (circle.getPosition().y >= bounce_bottom - (circle.getRadius()*2) || circle.getGlobalBounds().top <= bounce_top)
    {
        start_y *= -1;
//        setText(numbers[rand_num]);
        setBallStyle(all_color[rand_num]);
    }
    setStartPoints(start_x, start_y);
    circle.move(start_x, start_y);

}

void Ball::setBounds()
{
    /*
     * get position of the ball
     * compare with the window size
     *
     * the x cannot go further than size.x - radius*2 or smaller than 0
     * the y cannot go further than size.y - radius*2 or smaller than 0
     */
    bounce_top = circle.getOutlineThickness();
    bounce_left = circle.getOutlineThickness();
    bounce_bottom = 420;
    bounce_right = 720;

}

void Ball::setRadius(float radius)
{
    circle.setRadius(radius);
}

void Ball::setBallStyle(sf::Color color)
{
    circle.setFillColor(sf::Color::White);

// set a 10-pixel wide orange outline
    circle.setOutlineThickness(-10);
    circle.setOutlineColor(sf::Color(color));
}

void Ball::setText(std::string string)
{
    font.loadFromFile("FontsPortfolio/arial.ttf");

    text.setString(string);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
}

void Ball::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
//    window.draw(circle);

//    states.transform = circle.getTransform();
    window.draw(circle);
//    window.draw(text, states);
}



void Ball::centerText(const sf::CircleShape &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});

}
