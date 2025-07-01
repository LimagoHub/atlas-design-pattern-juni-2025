//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once

#include <string>
#include <ostream>
#include <functional>
#include <vector>
#include "Tier.h"
#include "PigTooFatListener.h"
namespace tiere {

    class Schwein: public Tier {

    private:
        inline static const unsigned MAX_WEIGHT{20};
        std::vector<std::function<void(Schwein *)>> listeners;
        std::vector<PigTooFatListener> pigTooFatlisteners;
        std::string name;
        int gewicht;

        inline void setGewicht(int gewicht) {
            Schwein::gewicht = gewicht;
            if (gewicht > MAX_WEIGHT) firePigTooFatEvent();
        }

        void firePigTooFatEvent() {
            for (const auto &listener: listeners) {
                listener(this);
            }
        }

    public:


        explicit Schwein(const std::string &name="Nobody") : name(name),gewicht(10) {}

        void addPigTooFatListener(const std::function<void(Schwein *)> &listener) {
            listeners.emplace_back(listener);
        }

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            Schwein::name = name;
        }

        int getGewicht() const {
            return gewicht;
        }

        void fuettern() {
            setGewicht(getGewicht() + 1);
        }

        friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
            os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
            return os;
        }

    };

} // tiere
