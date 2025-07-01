//
// Created by JoachimWagner on 29.10.2024.
//



#pragma once
#include <stdexcept>
#include "../TrafficLight.h"
#include "AbstractTrafficLightState.h"


namespace trafficlight::state {
    class AbstractTrafficLightColorState : public AbstractTrafficLightState {



    public:
        using AbstractTrafficLightState::AbstractTrafficLightState;

        ~AbstractTrafficLightColorState() override = default;



        void switchOff() override {
            getTrafficLight().current = getTrafficLight().off;
        }



    };
}
