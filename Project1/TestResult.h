#pragma once

#include <fstream>

#include "String.h"

namespace TestingSystem {

    struct TestResult {
        String testName;
        int correct = 0;
        int total = 0;
        int mark = 0;

        bool isPaused;
        int currentQuestion;
        Vector<int> userAnswers;

        void save(ofstream& out) const;
        void load(ifstream& in);
    };

    void TestResult::save(ofstream& out) const{
        testName.save(out);
        out.write((const char*)&correct, sizeof(correct));
        out.write((const char*)&total, sizeof(total));
        out.write((const char*)&mark, sizeof(mark));

        out.write((const char*)&isPaused, sizeof(isPaused));
        out.write((const char*)&currentQuestion, sizeof(currentQuestion));

        size_t s = userAnswers.get_size();
        out.write((const char*)&s, sizeof(s));
        for (size_t i = 0; i < s; ++i)
            out.write((const char*)&userAnswers.at(i), sizeof(userAnswers.at(i)));
    }

    void TestResult::load(ifstream& in) {
        testName.load(in);
        in.read((char*)&correct, sizeof(correct));
        in.read((char*)&total, sizeof(total));
        in.read((char*)&mark, sizeof(mark));

        in.read((char*)&isPaused, sizeof(isPaused));
        in.read((char*)&currentQuestion, sizeof(currentQuestion));

        size_t s; in.read((char*)&s, sizeof(s));
        userAnswers.clear();
        for (size_t i = 0; i < s; ++i) {
            int a;  in.read((char*)&a, sizeof(a)); userAnswers.push_back(a);
        }
    }
}