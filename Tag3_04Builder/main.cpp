#include <iostream>
#include "Person.h"


int main() {

    auto person = Person::builder().withAnrede("Mister").withVorname("John").withNachname("Doe").build();
    std::cout << *person << std::endl;

    return 0;
}
