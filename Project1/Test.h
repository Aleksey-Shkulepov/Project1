#pragma once

#include "Question.h"

#include <fstream>

#include "String.h"
#include "Vector.h"

namespace TestingSystem {

    struct Test {
        String name;
        Vector<Question> questions;

        Test() {}

        void save(ofstream& out) const;
        void load(ifstream& in);
    };

    void Test::save(ofstream& out) const {
        name.save(out);

        size_t s = questions.get_size();
        out.write((const char*)&s, sizeof(s));
        for (size_t i = 0; i < s; ++i)
            questions.at(i).save(out);
    }
    void Test::load(ifstream& in) {
        name.load(in);

        size_t s; in.read((char*)&s, sizeof(s));
        questions.clear();
        for (size_t i = 0; i < s; ++i) {
            Question q; q.load(in); questions.push_back(q);
        }
    }
}
