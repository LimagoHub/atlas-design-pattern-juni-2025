//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once
#include <iostream>
#include "AbstractMitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"
namespace mitarbeiter::visitor {

    class StatistikVisitor:public  AbstractMitarbeiterVisitor {
        int ge_counter;
        int le_counter;


    public:

        int getGeCounter() const {
            return ge_counter;
        }

        int getLeCounter() const {
            return le_counter;
        }

        int getTotal() const {
            return le_counter + ge_counter;
        }

        void start() override {
            ge_counter = le_counter = 0;
        }

        void finish() override {
            std::cout << *this << "\n";
        }

        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            ++le_counter;
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
           ++ ge_counter;
        }



        friend std::ostream &operator<<(std::ostream &os, const StatistikVisitor &visitor) {
            os << " ge_counter: " << visitor.ge_counter
               << " le_counter: " << visitor.le_counter
                    << " gesamt_counter: " << (visitor.le_counter+visitor.ge_counter);
            return os;
        }
    };

} // mitarbeiter
