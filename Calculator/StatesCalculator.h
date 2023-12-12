//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_STATESCALCULATOR_H
#define SFML_PROJECT_STATESCALCULATOR_H

#include "iostream"
#include "map"
#include "../StateEnumPortfolio.h"

class StatesCalculator
{
private:
    std::map<StateEnumPortfolio, bool> states;

public:
    StatesCalculator();
    void disableState(StateEnumPortfolio state);
    void enableState(StateEnumPortfolio state);
    void toggleState(StateEnumPortfolio state);
    bool getState(StateEnumPortfolio state) const;
};


#endif //SFML_PROJECT_STATESCALCULATOR_H
