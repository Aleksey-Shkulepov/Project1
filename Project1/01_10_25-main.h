#pragma once

#include "mystd.h"
#include "fullstd.h"

#include "SyntaxChecker.h"

namespace hw01_10_25 {
	void main() {
        String test1("({x-y-z} * [x + 2y] - (z + 4x));");
        String test2("([x-y-z} * [x + 2y) - {z + 4x]);");

        cout << test1 << (SyntaxChecker::checkBrackets(test1) ? " - Правильний рядок" : " - Неправильний рядок") << endl;
        cout << test2 << (SyntaxChecker::checkBrackets(test2) ? " - Правильний рядок" : " - Неправильний рядок");
    }
}