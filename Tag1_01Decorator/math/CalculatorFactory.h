//
// Created by JoachimWagner on 30.06.2025.
//

#pragma once
#include "CalculatorImpl.h"
#include "CalculatorLoggerDecorator.h"
#include "CalculatorSecureDecorator.h"

using CalcPointer = std::unique_ptr<math::Calculator>;
namespace math {

    class CalculatorFactory {

        inline static bool logger{false};
        inline static bool secure{false};

    public:

        static bool isLogger() {
            return logger;
        }

        static void setLogger(bool logger) {
            CalculatorFactory::logger = logger;
        }

        static bool isSecure() {
            return secure;
        }

        static void setSecure(bool secure) {
            CalculatorFactory::secure = secure;
        }

        static CalcPointer create() {
            CalcPointer result = std::make_unique<CalculatorImpl>();
            if(logger) result = std::make_unique<CalculatorLoggerDecorator>(std::move(result));
            if(secure) result = std::make_unique<CalculatorSecureDecorator>(std::move(result));
            return result;
        }


    };

} // math
