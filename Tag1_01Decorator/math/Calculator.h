//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once

#include <iostream>

namespace math {

    class Calculator {

    public:
        Calculator() = default;

        ~Calculator() = default;

        virtual double add(double a, double b)= 0;

        virtual double sub(double a, double b)=0;
    };

} // math
