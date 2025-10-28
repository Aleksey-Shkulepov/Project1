#pragma once

#include "DAI.h"

namespace hw22_10_25 {

    void main() {
        DAI dai;

        dai.addFine("AA1234BB", "Превышение скорости");
        dai.addFine("AA1234BB", "Парковка в запрещенном месте");
        dai.addFine("BC9876AA", "Проезд на красный сигнал светофора");
        dai.addFine("AB1111CC", "Неисправные фары");

        cout << "Полная база данных" << endl;
        dai.printAll();

        cout << "Данные по номеру AA1234BB" << endl;
        dai.printByPlate("AA1234BB");

        cout << "Данные по диапазону [AA0000AA - AB9999ZZ]" << endl;
        dai.printByRange("AA0000AA", "AB9999ZZ");

        cout << "Поиск отсутствующего номера" << endl;
        dai.printByPlate("ZZ9999ZZ");
    }
}