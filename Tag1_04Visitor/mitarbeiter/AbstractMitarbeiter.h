//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once

#include <string>
#include <ostream>
#include "visitor/MitarbeiterVisitor.h"
using VISITOR=mitarbeiter::visitor::MitarbeiterVisitor;
namespace mitarbeiter {

    class AbstractMitarbeiter {
        std::string name;
    public:
        explicit AbstractMitarbeiter(const std::string &name) : name(name) {}

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            AbstractMitarbeiter::name = name;
        }
        virtual std::string toString() const {
            return "Name = " + getName();
        }
        friend std::ostream &operator<<(std::ostream &os, const AbstractMitarbeiter &abstractMitarbeiter) {
            os << abstractMitarbeiter.toString();
            return os;
        }

        virtual void accept(VISITOR &visitor) = 0;
    };

} // mitarbeiter
