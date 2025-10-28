#pragma once

#include "DAI.h"

namespace hw22_10_25 {

    void main() {
        DAI dai;

        dai.addFine("AA1234BB", "���������� ��������");
        dai.addFine("AA1234BB", "�������� � ����������� �����");
        dai.addFine("BC9876AA", "������ �� ������� ������ ���������");
        dai.addFine("AB1111CC", "����������� ����");

        cout << "������ ���� ������" << endl;
        dai.printAll();

        cout << "������ �� ������ AA1234BB" << endl;
        dai.printByPlate("AA1234BB");

        cout << "������ �� ��������� [AA0000AA - AB9999ZZ]" << endl;
        dai.printByRange("AA0000AA", "AB9999ZZ");

        cout << "����� �������������� ������" << endl;
        dai.printByPlate("ZZ9999ZZ");
    }
}