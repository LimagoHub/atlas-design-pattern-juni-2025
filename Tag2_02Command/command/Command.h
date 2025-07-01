//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once

#include <vector>
#include <string>

namespace command {

    class Command {



    public:
        using StringVector=std::vector<std::string>;
        virtual ~Command() = default;
        virtual auto parse(const StringVector &tokens) ->void = 0;
        virtual auto execute()->void = 0;
        virtual auto undo()->void = 0;
        virtual auto isQuery()->bool = 0;
    };

} // command
