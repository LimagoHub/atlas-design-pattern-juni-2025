//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once

#include <iostream>

class Singleton {
    Singleton() = default;

public:
    Singleton(Singleton const&)               = delete;
    auto operator=(Singleton const&)->void    = delete;

    Singleton(Singleton &&)               = delete;
    auto operator=(Singleton &&)->void    = delete;
    static auto create()->Singleton & { // Lazy + Threadsafe
        static Singleton instance;
        return instance;
    }
    auto log(std::string message)->void{
        std::cout << message << std::endl;
    }
};
