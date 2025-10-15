#pragma once

#include <fstream>

#include "String.h"

namespace TestingSystem {

    struct TestResult {
        String testName;
        int correct = 0;
        int total = 0;
        int mark = 0;

        void save(ofstream& out) const;
        void load(ifstream& in);
    };

    void TestResult::save(ofstream& out) const{
        testName.save(out);
        out.write((const char*)&correct, sizeof(correct));
        out.write((const char*)&total, sizeof(total));
        out.write((const char*)&mark, sizeof(mark));
    }

    void TestResult::load(ifstream& in) {
        testName.load(in);
        in.read((char*)&correct, sizeof(correct));
        in.read((char*)&total, sizeof(total));
        in.read((char*)&mark, sizeof(mark));
    }
}