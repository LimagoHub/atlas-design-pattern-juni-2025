#include <iostream>
#include "tiere/Schwein.h"
#include "tiere/PigTooFatListener.h"

class Metzger {
public:
    void schlachten(tiere::Tier *tier) {
        std::cout << "Messer wetz" << std::endl;
    }
};

class Schlachter: public tiere::PigTooFatListener {
public:
    void pigTooFat(tiere::Schwein *schwein) override {
        std::cout << "Messer wetz" << std::endl;
    }
};
template<class T>
class Spediteur {
public:
    void fahren(T *Ware) {
        std::cout << "Wir fahren auf der Autobahn" << std::endl;
    }
};

int main() {
    Metzger metzger;
    Spediteur<tiere::Schwein> spediteur;

    tiere::Schwein piggy{"Miss piggy"};
    piggy.addPigTooFatListener([&metzger](tiere::Schwein *s){metzger.schlachten(s);});
    piggy.addPigTooFatListener([&spediteur](tiere::Schwein *s){spediteur.fahren(s);});


    for (int i = 0; i < 11; ++i) {
        piggy.fuettern();
    }
    return 0;
}
