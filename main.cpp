#include <iostream>
#include "Portfolio.h"
#include "Galaga/Galaga.h"
#include "SFML_Template/greenCircle.h"
#include "Calculator/Calculator.h"
#include "Clock/Clock.h"
#include "Poker Analysis w SFML/PokerAnalysis.h"
#include "BouncingBall/BouncingBall.h"
int main() {

    Portfolio portfolio;

    Galaga galaga;
    greenCircle greenCircle;
    BouncingBall bouncingBall;
    Calculator calculator;
    Clock clock;
    PokerAnalysis pokerAnalysis;


    portfolio.addProject(greenCircle);
    portfolio.addProject(bouncingBall);
    portfolio.addProject(clock);
    portfolio.addProject(pokerAnalysis);
    portfolio.addProject(calculator);
    portfolio.addProject(galaga);

    portfolio.run();

    return 0;
}
