//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include <memory>
#include "Command.h"
#include "AddCommand.h"
#include "PrintCommand.h"
#include <regex>

namespace command {
    using COMMAND = std::shared_ptr<command::Command>;
    using StringVector=std::vector<std::string>;

    class CommandFactory {
    public:

        static COMMAND create(std::string line) {
            COMMAND result;
            const StringVector tokens =tokenizeLine(line);
            if(tokens[0] == "Add"){
                result = std::make_shared<AddCommand>();
                result->parse(tokens);
            }
            if(tokens[0] == "Print"){
                result = std::make_shared<PrintCommand>();
                result->parse(tokens);
            }
            return result;
        }

    private:
        static StringVector tokenizeLine(const std::string &line) {
            auto const regex = std::regex{R"(\s+)"};
            auto const result = StringVector(
                    std::sregex_token_iterator{std::begin(line), std::end(line), regex, -1},
                    std::sregex_token_iterator{}
            );
            return result;
        }
    };


} // command
