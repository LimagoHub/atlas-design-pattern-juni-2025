//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once

namespace mitarbeiter {
    class GehaltsEmpfaenger;
    class LohnEmpfaenger;
}

namespace mitarbeiter::visitor {

    class MitarbeiterVisitor {
    public:

        virtual ~MitarbeiterVisitor()= default;

        virtual void start() = 0;
        virtual void finish() = 0;

        virtual void visit(mitarbeiter::LohnEmpfaenger &lohn_empfaenger) = 0;

        virtual void visit(mitarbeiter::GehaltsEmpfaenger &gehalts_empfaenger) = 0;
    };

} // mitarbeiter
