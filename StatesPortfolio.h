//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_STATESPORTFOLIO_H
#define SFML_PROJECT_STATESPORTFOLIO_H

#include "iostream"
#include "map"
#include "StateEnumPortfolio.h"

class StatesPortfolio
{
private:
    std::map<StateEnumPortfolio, bool> states;

public:
    StatesPortfolio();
    void disableState(StateEnumPortfolio state);
    void enableState(StateEnumPortfolio state);
    void toggleState(StateEnumPortfolio state);
    bool getState(StateEnumPortfolio state) const;
};


#endif //SFML_PROJECT_STATESPORTFOLIO_H
