//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once

#include <memory>
#include <iostream>
#include "CalculatorMemento.h"

namespace math {

    class Calculator {
        double memory{0};

        Calculator() {}

        void setMemory(double memory) {
            Calculator::memory = memory;
        }

        class MyCalculatorMemento :public CalculatorMemento {
            const double memory;
        public:
            explicit MyCalculatorMemento(const double memory) : memory(memory) {}

            const double getMemory() const {
                return memory;
            }
        };
    public:

        const std::shared_ptr<CalculatorMemento> &getMemento() const {
            return std::make_shared<MyCalculatorMemento>(memory);
        }

        void setMemento(const std::shared_ptr<CalculatorMemento> &memento) {
            auto myMemento = std::dynamic_pointer_cast<MyCalculatorMemento>(memento);
            setMemory(myMemento->getMemory());
        }

        [[nodiscard]] static auto getInstance()->std::shared_ptr<Calculator>  {
            static std::shared_ptr<Calculator> instance{new Calculator{}};

            return instance;
        }

        double getMemory() const {
            return memory;
        }


        auto print() const->void{
            std::cout << memory << std::endl;
        }
        auto clear()-> void {
            memory = 0;
        }

        auto add(double value)-> void {
            memory += value;
        }
        auto sub(double value)-> void {
            memory -= value;
        }
        auto mult(double value)-> void {
            memory *= value;
        }
        auto div(double value)-> void {
            memory /= value;
        }

    };

} // math
