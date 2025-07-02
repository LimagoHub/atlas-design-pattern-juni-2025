//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include "AbstractQuery.h"
#include "../math/Calculator.h"
namespace command {
    using Calc=math::Calculator;

    class PrintCommand: public AbstractQuery{
    public:
        ~PrintCommand() override = default;

        auto execute() -> void override {
            Calc ::getInstance()->print();
        }
    };

} // command
