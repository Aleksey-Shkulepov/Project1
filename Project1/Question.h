#pragma once

#include <fstream>

#include "String.h"
#include "Vector.h"

namespace TestingSystem {

    struct Question {
        String text;
        Vector<String> options;
        int correctIndex = -1;

        Question() {}

        void save(ofstream& out) const;
        void load(ifstream& in);
    };

    void Question::save(ofstream& out) const {
        text.save(out);

        size_t s = options.get_size();
        out.write((const char*)&s, sizeof(s));
        for (size_t i = 0; i < s; ++i)
            options.at(i).save(out);

        out.write((const char*)&correctIndex, sizeof(correctIndex));
    }

    void Question::load(ifstream& in) {
        text.load(in);

        size_t s; in.read((char*)&s, sizeof(s));
        options.clear();
        for (size_t i = 0; i < s; ++i) {
            String str; str.load(in); options.push_back(str);
        }

        in.read((char*)&correctIndex, sizeof(correctIndex));
    }
}