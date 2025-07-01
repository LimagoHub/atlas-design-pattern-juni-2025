//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include <memory>
#include <iostream>
#include <stack>
#include "Command.h"
namespace command {
    using CommandPointer = std::shared_ptr<Command>;

    class CommandHistory {
        std::stack<CommandPointer> undoStack;
        std::stack<CommandPointer> redoStack;
    public:
        virtual ~CommandHistory()=default;
        CommandHistory()=default;

        auto add(const CommandPointer &c )->void {
            if(c->isQuery()) return;
            std::stack<CommandPointer>().swap(redoStack);// Loescht den RedoStack
            // Insert your code here
        }
        auto undo()->void {
            std::cout << "Can't undo" << std::endl;
        }
        auto redo()->void {
            std::cout << "Can't redo" << std::endl;
        }


    };

} // command
