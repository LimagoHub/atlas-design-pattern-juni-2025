cmake_minimum_required(VERSION 3.31)
project(Tag1_01Decorator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tag1_01Decorator main.cpp math/CalculatorImpl.h
        math/CalculatorLoggerDecorator.h
        math/CalculatorFactory.h)
