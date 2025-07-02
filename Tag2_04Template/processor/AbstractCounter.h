//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include <iostream>
#include "CharacterHandler.h"
namespace processor {

    class AbstractCounter:public CharacterHandler {
        size_t counter;
    public:
        void init() final {
            counter = 0;
        }

        void dispose() final {
            std::cout << typeid(*this).name() << ": " << counter << std::endl;

        }

    protected:
        void incrementCounter() {
            counter ++;
        }
    };

} // processor
