cmake_minimum_required(VERSION 3.17)
project(Tag1_06TrafficLight_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag1_06TrafficLight_ main.cpp
        trafficlight/state/TrafficLightState.h
        trafficlight/TrafficLight.cpp
        trafficlight/TrafficLight.h)
