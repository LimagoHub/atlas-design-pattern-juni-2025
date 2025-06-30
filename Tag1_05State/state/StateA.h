//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once

#include <iostream>
#include "AbstractState.h"

class StateA: public AbstractState{
public:

    explicit StateA(FrontController *frontController) : AbstractState(frontController) {}

    void drucken() override {
        std::cout << "Hier druckt A" << std::endl;
    }

    void changeToB() override {
        getFrontController()->current = getFrontController()->stateB;
    }
};
