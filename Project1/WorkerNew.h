#pragma once

#include "mystd.h"

#include "Employer.h"

namespace hw26_10_25 {

    class Worker : public Employer {
    public:
        String position;

        Worker(const String& n, const String& p) : Employer(n), position(p) {}

        void Print() const override {
            cout << "Worker: " << name << ", Position: " << position << endl;
        }

        void DoTask() const {
            cout << name << " is doing a task." << endl;
        }

        void TakeBreak() const {
            cout << name << " is taking a break." << endl;
        }
    };

}