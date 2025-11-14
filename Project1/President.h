#pragma once

#include "mystd.h"

#include "Employer.h"

namespace hw26_10_25 {

    class President : public Employer {
    public:
        String country;

        President(const String& n, const String& c) : Employer(n), country(c) {}

        void Print() const override {
            cout << "President: " << name << ", Country: " << country << endl;
        }

        void makeNewLaw(const String& law) const {
            cout << "A new law has been added to the constitution. Law: " << law << endl;
        }
    };

}