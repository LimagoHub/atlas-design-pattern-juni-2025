//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once

namespace processor {

    class CharacterHandler {

    public:
        CharacterHandler() = default;

        virtual ~CharacterHandler()= default;

        virtual void init() = 0;
        virtual void process(char c) = 0;
        virtual void dispose() = 0;

    };

} // processor
