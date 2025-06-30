//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once

#include <memory>
#include "Calculator.h"

namespace math {

    class CalculatorLoggerDecorator: public Calculator {
        using CalcPointer = std::unique_ptr<math::Calculator>;
        CalcPointer calculator_;

    public:
        explicit CalculatorLoggerDecorator(CalcPointer calculator) : calculator_(std::move(calculator)) {}

        double add(double a, double b) override {
            std::cout << "Add wurde gerufen\n";
            return calculator_->add(a,b);
        }

        double sub(double a, double b) override {
            return 0;
        }

    };

} // math
