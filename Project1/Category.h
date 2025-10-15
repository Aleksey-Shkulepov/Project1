#pragma once

#include "Test.h"

#include <fstream>

#include "String.h"
#include "Vector.h"

namespace TestingSystem {

    struct Category {
        String name;
        Vector<Test> tests;

        void save(ofstream& out) const;
        void load(ifstream& in);
    };

    void Category::save(ofstream& out) const {
        name.save(out);

        size_t s = tests.get_size();
        out.write((const char*)&s, sizeof(s));
        for (size_t i = 0; i < s; ++i)
            tests.at(i).save(out);
    }
    void Category::load(ifstream& in) {
        name.load(in);

        size_t s; in.read((char*)&s, sizeof(s));
        tests.clear();
        for (size_t i = 0; i < s; ++i) {
            Test t; t.load(in); tests.push_back(t);
        }
    }
}

