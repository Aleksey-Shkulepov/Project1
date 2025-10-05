#pragma once

#include "mystd.h"

namespace hw04_10_25
{
    struct Client {
        String name;
        String document;
        int pages;

        friend ostream& operator<<(ostream& os, const Client& c) {
            os << c.name << " (" << c.document << ", " << c.pages << " стор.)";
            return os;
        }
    };
}

