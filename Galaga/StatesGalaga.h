//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_STATESGALAGA_H
#define SFML_PROJECT_STATESGALAGA_H

#include "iostream"
#include "map"
//#include "StateEnumGalaga.h"
#include "../StateEnumPortfolio.h"

class StatesGalaga
{
private:
    std::map<StateEnumPortfolio, bool> states;

public:
    StatesGalaga();
    void disableState(StateEnumPortfolio state);
    void enableState(StateEnumPortfolio state);
    void toggleState(StateEnumPortfolio state);
    bool getState(StateEnumPortfolio state) const;
};


#endif //SFML_PROJECT_STATESGALAGA_H
