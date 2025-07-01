//
// Created by JoachimWagner on 30.06.2025.
//

#include <memory>
#include "TrafficLight.h"
#include "state/TrafficLightState.h"
#include "state/RedState.h"
#include "state/GreenState.h"
#include "state/OffState.h"

trafficlight::TrafficLight::TrafficLight():
        red(std::make_shared<trafficlight::state::RedState>(*this)) ,
        green(std::make_shared<trafficlight::state::GreenState>(*this)),
        off(std::make_shared<trafficlight::state::OffState>(*this)),
        current(off)
{}

std::string trafficlight::TrafficLight::getColor() {
    return current->getColor();
}

void trafficlight::TrafficLight::nextColor() {
    current->nextColor();
}

void trafficlight::TrafficLight::switchOff() {
    current->switchOff();
}

void trafficlight::TrafficLight::switchOn() {
    current->switchOn();
}
