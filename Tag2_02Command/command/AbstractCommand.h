//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include <stdexcept>
#include "Command.h"
namespace command {
    class AbstractCommand: public Command{
    public:
        AbstractCommand()=default;
        ~AbstractCommand() override = default;

        auto parse(const StringVector &tokens)->void override {
            // Ok
        }

        auto undo() -> void override {
            throw std::logic_error{"Upps"};

        }

        auto isQuery() -> bool override {
            return true;
        }
    };
}
