//
// Created by ASUS on 11/14/2023.
//

#include "StatesPortfolio.h"

StatesPortfolio::StatesPortfolio() {
    for (int i = 0; i < LAST_STATE; ++i)
    {
        states[static_cast<StateEnumPortfolio>(i)] = false;
    }
}

void StatesPortfolio::disableState(StateEnumPortfolio state) {
    states[state] = false;
}

void StatesPortfolio::enableState(StateEnumPortfolio state) {
    states[state] = true;
}

void StatesPortfolio::toggleState(StateEnumPortfolio state) {
    states[state] = !states[state];
}

bool StatesPortfolio::getState(StateEnumPortfolio state) const {
    return states.at(state);
}
