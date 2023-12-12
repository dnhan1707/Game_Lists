//
// Created by ASUS on 11/14/2023.
//

#include "Calculator.h"

Calculator::Calculator()
{
    background.setSize({300, 450});
    background.setFillColor(sf::Color{28, 28, 28});

    ///PositionCalculator background
    background.setPosition({100, 100});

    ///PositionCalculator display
    PositionCalculator::alignCenterAndInside(background, display.getDisplayBox());

    display.setSize({300, 100});
    display.setColor(sf::Color{28, 28, 28});
    display.setText("0");


    sf::Color lightgrey = sf::Color{187,187,185};
    sf::Color darkLiver = sf::Color{80, 80, 80};
    sf::Color orange = sf::Color{255, 149, 0};


    ButtonCalculator zero("0", darkLiver);
    ButtonCalculator one("1", darkLiver);
    ButtonCalculator two("2", darkLiver);
    ButtonCalculator three("3", darkLiver);
    ButtonCalculator four("4", darkLiver);
    ButtonCalculator five("5", darkLiver);
    ButtonCalculator six("6", darkLiver);
    ButtonCalculator seven("7", darkLiver);
    ButtonCalculator eight("8", darkLiver);
    ButtonCalculator nine("9", darkLiver);
    ButtonCalculator plus("+", orange);
    ButtonCalculator minus("-", orange);
    ButtonCalculator mult("*", orange);
    ButtonCalculator div("/", orange);
    ButtonCalculator equal("=", orange);
    ButtonCalculator allClear("AC", lightgrey, sf::Color{28, 28, 28});
    ButtonCalculator mod("%", lightgrey, sf::Color{28, 28, 28});
    ButtonCalculator negative_positive("+/-", lightgrey, sf::Color{28, 28, 28});
    ButtonCalculator dot(".", darkLiver);


    buttons = {allClear, negative_positive, mod, div, seven, eight, nine, mult, four, five, six, minus, one, two, three, plus, zero, dot, equal};
    /// PositionCalculator button
    PositionCalculator::belowAndAlignCenterForCircleInObject(display.getDisplayBox(), buttons[0].getButton());

    /// PositionCalculator text in DisplayCalculator
    sf::FloatRect display_bounce = display.getDisplayBox().getGlobalBounds();
    float button_rad = buttons[0].getButton().getRadius();
    float margin_x = (display_bounce.width/ 2) - (button_rad * 4);

    PositionCalculator::alignLeft(display.getDisplayBox(), display.getTextObject(), margin_x, margin_x);
    for (int i = 1; i < 20; i++) {
        if (i == 4 || i == 8 || i == 12 || i == 16)
        {
            PositionCalculator::below(buttons[i - 4].getButton(), buttons[i].getButton());
        }
        else
        {
            PositionCalculator::right(buttons[i - 1].getButton(), buttons[i].getButton());
        }
    }
}

void Calculator::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(display);
    for (int i = 0; i < 19; ++i) {
        window.draw(buttons[i]);
    }
}

void Calculator::eventHandler(sf::RenderWindow &window, sf::Event event) {
    std::cout.setf(std::ios::showpoint);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    for (int i = 0; i < 19; i++) {
        buttons[i].eventHandler(window, event);
        buttons[i].update();
        if (buttons[i].getState(CLICK)) {
            std::string buttonText = buttons[i].getText();
            if (buttonText == "=")
            {
                if (expression.length() > 2)
                {
                    double res = RPN::evaluate(RPN::toRPN(expression));
                    display.setText(std::to_string(res));
                    resetExpression();
                }
                else display.setText(expression);
            }
            else if(buttonText == "AC")
            {
                resetExpression();
                display.setText("0");
            }
            else {
                setExpression(buttonText);
                display.setText(expression);
            }
        }
    }
}

void Calculator::setExpression(const std::string& character)
{
    expression += character;
}

void Calculator::resetExpression() {
    expression = "";
}

void Calculator::update() {

}

void Calculator::run() {

}

std::string Calculator::getName() {
    return "Calculator";
}
