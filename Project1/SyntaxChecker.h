#pragma once

#include "mystd.h"
#include "fullstd.h"

namespace hw01_10_25 {

    class SyntaxChecker {
    public:
        static bool checkBrackets(const String& str) {
            Stack<char> stack;
            for (size_t i = 0; i < str.get_length(); i++) {
                char c = str[i];
                if (c == '(' || c == '{' || c == '[') {
                    stack.push(c);
                }
                else if (c == ')' || c == '}' || c == ']') {
                    if (stack.isEmpty()) return false;
                    char peek = stack.peek();
                    if (!(
                        (peek == '(' and c == ')') or
                        (peek == '{' and c == '}') or
                        (peek == '[' and c == ']')
                        )) return false;
                    stack.pop();
                }
                else if (c == ';') break;
            }
            if (!stack.isEmpty()) return false;
            return true;
        }
    };
}

