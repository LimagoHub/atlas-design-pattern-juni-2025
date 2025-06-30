//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once
#include <iostream>
#include "AbstractMitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"
namespace mitarbeiter::visitor {

    class PrintVisitor: public AbstractMitarbeiterVisitor{
    public:
        ~PrintVisitor() override = default;

        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            std::cout << lohn_empfaenger << "\n";
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            std::cout << gehalts_empfaenger << "\n";
        }
    };

} // mitarbeiter
