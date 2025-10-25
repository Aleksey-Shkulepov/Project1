#pragma once

#include "Pet.h"
#include "BitString.h"

namespace hw25_10_25 {

    void main() {
        Dog dog("Дурка", "Породистый");
        Cat cat("Что где когда", "Голубой");
        Parrot parrot("ПАПУГА", true);

        dog.showInfo();
        cat.showInfo();
        parrot.showInfo();

        BitString b1("1010");
        BitString b2("011");
        BitString b3 = b1 + b2;
        cout << "До " << b3 << endl;
        b3.invertSign();
        cout << "После " << b3 << endl;
    }

}