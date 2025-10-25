#pragma once

#include "Pet.h"
#include "BitString.h"

namespace hw25_10_25 {

    void main() {
        Dog dog("�����", "����������");
        Cat cat("��� ��� �����", "�������");
        Parrot parrot("������", true);

        dog.showInfo();
        cat.showInfo();
        parrot.showInfo();

        BitString b1("1010");
        BitString b2("011");
        BitString b3 = b1 + b2;
        cout << "�� " << b3 << endl;
        b3.invertSign();
        cout << "����� " << b3 << endl;
    }

}