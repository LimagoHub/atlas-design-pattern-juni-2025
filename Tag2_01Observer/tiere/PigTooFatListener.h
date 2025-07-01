//
// Created by JoachimWagner on 01.07.2025.
//

#pragma once
#include "Schwein.h"


namespace tiere {
    class Schwein;
    class PigTooFatListener {

    public:
        virtual void pigTooFat(Schwein *schwein) = 0;
    };

} // tiere
