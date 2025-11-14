#pragma once

#include "mystd.h"

namespace hw26_10_25 {

    class Employer {
    public:
        String name;

        Employer(const String& n) : name(n) {}

        virtual void Print() const = 0;

        virtual ~Employer() {}
    };

}