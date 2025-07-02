cmake_minimum_required(VERSION 3.17)
project(Tag3_01Composite)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag3_01Composite main.cpp
        composite/AbstractNode.h
        composite/Leaf.h
        composite/Node.h)
