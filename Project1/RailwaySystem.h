#pragma once

#include "mystd.h"

#include "Train.h"

class RailwaySystem {
private:
    Vector<Train> trains;

public:
    void addTrain(const Train& t) {
        trains.push_back(t);
    }

    void showAll() const {
        if (trains.is_empty()) {
            cout << "The list is empty" << endl; return;
        }

        for (const auto& t : trains)
            cout << t << endl;
    }

    const Train* searchTrainByNumber(int number) const {
        for (const auto& t : trains)
            if (t.number == number)
                return &t;
        return nullptr;
    }

    const Train* searchTrainByStation(String destination) const {
        for (const auto& t : trains)
            if (t.destination == destination)
                return &t;
        return nullptr;
    }
};