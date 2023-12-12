//
// Created by ASUS on 11/14/2023.
//

#include "StatesCalculator.h"

StatesCalculator::StatesCalculator() {
    for (int i = 0; i < LAST_STATE; ++i)
    {
        states[static_cast<StateEnumPortfolio>(i)] = false;
    }
}

void StatesCalculator::disableState(StateEnumPortfolio state) {
    states[state] = false;
}

void StatesCalculator::enableState(StateEnumPortfolio state) {
    states[state] = true;
}

void StatesCalculator::toggleState(StateEnumPortfolio state) {
    states[state] = !states[state];
}

bool StatesCalculator::getState(StateEnumPortfolio state) const {
    return states.at(state);
}
