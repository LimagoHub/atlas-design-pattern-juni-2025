//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once
#include <iostream>
#include "Calculator.h"

namespace math {

    class CalculatorImpl : public Calculator {
    public:
        double add(double a, double b) override {

            return a + b;
        }

        double sub(double a, double b) override {
            return a - b;
        }
    };

} // math
