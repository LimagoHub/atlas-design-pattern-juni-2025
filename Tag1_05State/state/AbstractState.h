//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once
#include <stdexcept>
#include "State.h"
#include "../FrontController.h"

class AbstractState:public State{
    FrontController * frontController;

public:
    explicit AbstractState(FrontController *frontController) : frontController(frontController) {}

    ~AbstractState() override = default;

    void drucken() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToA() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToB() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

protected:
    FrontController *getFrontController() const {
        return frontController;
    }
};
