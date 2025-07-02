//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include <iostream>
#include "AbstractCounter.h"
namespace processor {

    class CharacterCounter: public AbstractCounter{
    public:
        void process(char c) override {
            incrementCounter();
        }


    };

} // processor
