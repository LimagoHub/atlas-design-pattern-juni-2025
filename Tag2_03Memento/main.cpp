#include <iostream>
#include "tiere/Schwein.h"
int main() {

    tiere::Schwein piggy {"Miss Piggy"};

    std::cout << piggy << std::endl;

    auto memento = piggy.getMemento();
    piggy.fuettern();
    std::cout << piggy << std::endl;

    // Zustand wieder herstellen
    piggy.setMemento(memento);
    std::cout << piggy << std::endl;

    return 0;
}
