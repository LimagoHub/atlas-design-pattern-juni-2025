cmake_minimum_required(VERSION 3.31)
project(Tag2_02Command)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_02Command main.cpp
        command/Command.h
        math/Calculator.h
        command/AbstractQuery.h
        command/AddCommand.h
        command/PrintCommand.h
        command/CommandFactory.h
        command/CommandHistory.h
        command/ClearCommand.h
        math/CalculatorMemento.h
        command/AbstractCommand.h)
