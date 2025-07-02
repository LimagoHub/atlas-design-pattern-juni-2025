//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include "AbstractCommand.h"
#include "../math/CalculatorMemento.h"
#include "../math/Calculator.h"
namespace command {
    using Calc=math::Calculator;

    class ClearCommand :public AbstractCommand{

    protected:
        void doAction() override {
            Calc ::getInstance()->clear();
        }
    };

} // command
