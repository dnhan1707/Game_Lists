//
// Created by ASUS on 11/14/2023.
//

#include "StatesGalaga.h"

StatesGalaga::StatesGalaga() {
    for (int i = 0; i < LAST_STATE; ++i)
    {
        states[static_cast<StateEnumPortfolio>(i)] = false;
    }
}

void StatesGalaga::disableState(StateEnumPortfolio state) {
    states[state] = false;
}

void StatesGalaga::enableState(StateEnumPortfolio state) {
    states[state] = true;
}

void StatesGalaga::toggleState(StateEnumPortfolio state) {
    states[state] = !states[state];
}

bool StatesGalaga::getState(StateEnumPortfolio state) const {
    return states.at(state);
}
