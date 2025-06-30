#include <iostream>
#include "math/CalculatorFactory.h"

#include "client/CalcClient.h"

using CalcPointer = std::unique_ptr<math::Calculator>;

int main() {

    math::CalculatorFactory::setLogger(true);
    math::CalculatorFactory::setSecure(true);
    CalcPointer calc = math::CalculatorFactory::create();

    CalcClient client{std::move(calc)};
    client.go();
    return 0;
}
