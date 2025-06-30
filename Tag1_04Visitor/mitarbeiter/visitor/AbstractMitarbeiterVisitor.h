//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once
#include "MitarbeiterVisitor.h"
namespace mitarbeiter::visitor {

    class AbstractMitarbeiterVisitor : public MitarbeiterVisitor{
    public:

        void start() override {
            // OK
        }

        void finish() override {
            // OK
        }

        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            // OK
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            //ok
        }
    };

} // mitarbeiter
