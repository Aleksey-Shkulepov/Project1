#pragma once

#include "String.h"

namespace hw25_10_25 {

    class BitString : public String {
    private:
        bool isValid(const char* s) const {
            if (!s) return false;
            for (size_t i = 0; i < strlen(s); i++)
                if (s[i] != '0' and s[i] != '1')
                    return false;
            return true;
        }
    public:
        BitString(int size = 0) : String(size) {}

        BitString(const char* s) {
            if (isValid(str)) {
                size = strlen(s);
                str = new char[size + 1];
                strcpy_s(str, size + 1, s);
            }
            else {
                str = nullptr;
                size = 0;
            }
        }

        BitString(const BitString& other) : String(other) {}

        BitString& operator=(const BitString& other)
        {
            if (this == &other) return *this;
            String::operator=(other);
            return *this;
        }

        BitString operator+(const BitString& other) const
        {
            BitString res(size + other.size);
            strcpy_s(res.str, res.size + 1, str);
            strcat_s(res.str, res.size + 1, other.str);
            return res;
        }

        void invertSign()
        {
            if (!str or size == 0) return;

            for (size_t i = 0; i < size; i++)
                str[i] = (str[i] == '0') ? '1' : '0';

            for (int i = size - 1; i >= 0; i--) {
                if (str[i] == '0') {
                    str[i] = '1';
                    break;
                }
                else str[i] = '0';
            }
        }

        bool is_valid() const {
            return isValid(str);
        }
    };

}