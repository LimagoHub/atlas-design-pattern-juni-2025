//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include "AbstractCommand.h"
#include "../math/Calculator.h"
namespace command {
    using Calc=math::Calculator;

    class AddCommand:public AbstractCommand{

    private:
        double value;

    public:
        AddCommand()=default;
        ~AddCommand() override = default;

        auto parse(const StringVector &tokens)->void override {
            value = std::stod(tokens[1]);
        }

        void doAction() override {
            Calc::getInstance()->add(value);
        }

    };

} // command
