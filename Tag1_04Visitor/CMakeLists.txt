cmake_minimum_required(VERSION 3.31)
project(Tag1_04Visitor)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tag1_04Visitor main.cpp
        mitarbeiter/AbstractMitarbeiter.h
        mitarbeiter/LohnEmpfaenger.h
        mitarbeiter/GehaltsEmpfaenger.h
        firma/Firma.h
        mitarbeiter/visitor/MitarbeiterVisitor.h
        mitarbeiter/visitor/AbstractMitarbeiterVisitor.h
        mitarbeiter/visitor/PrintVisitor.h
        mitarbeiter/visitor/StatistikVisitor.h)
