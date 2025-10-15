#pragma once

namespace hw08_10_25
{
    struct Passenger {
        size_t arrivalTimeMs;

        Passenger(size_t t) : arrivalTimeMs(t) {}
    };
}