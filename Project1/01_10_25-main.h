#pragma once

#include "mystd.h"
#include "fullstd.h"

#include "SyntaxChecker.h"

namespace hw01_10_25 {
	void main() {
        String test1("({x-y-z} * [x + 2y] - (z + 4x));");
        String test2("([x-y-z} * [x + 2y) - {z + 4x]);");

        cout << test1 << (SyntaxChecker::checkBrackets(test1) ? " - ���������� �����" : " - ������������ �����") << endl;
        cout << test2 << (SyntaxChecker::checkBrackets(test2) ? " - ���������� �����" : " - ������������ �����");
    }
}