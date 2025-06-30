//
// Created by JoachimWagner on 30.06.2025.
//
#include <iostream>
#include <memory>
#include "../math/Calculator.h"

#pragma once


class CalcClient {

    std::unique_ptr<math::Calculator> calc;

public:
    explicit CalcClient(std::unique_ptr<math::Calculator> calc) : calc(std::move(calc)) {}

public:
    void go() {

        auto result = calc->add(3,4);
        std::cout << result << std::endl;
    }
};
