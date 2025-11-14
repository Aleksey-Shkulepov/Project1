#pragma once

#include "mystd.h"

#include "Employer.h"

namespace hw26_10_25 {

    class Manager : public Employer {
    public:
        int teamSize;

        Manager(const String& n, int t) : Employer(n), teamSize(t) {}

        void Print() const override {
            cout << "Manager: " << name << ", Team Size: " << teamSize << endl;
        }

        void AssignTask() const {
            cout << name << " is assigning tasks to the team." << endl;
        }

        void HoldMeeting() const {
            cout << name << " is holding a meeting." << endl;
        }
    };

}