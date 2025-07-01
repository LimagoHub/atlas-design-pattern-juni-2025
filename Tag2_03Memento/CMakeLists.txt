cmake_minimum_required(VERSION 3.17)
project(Tag2_03Memento)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_03Memento main.cpp
        tiere/Schwein.h
        tiere/SchweineMemento.h)
