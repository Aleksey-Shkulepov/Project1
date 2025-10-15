#pragma once

#include "Stop.h"

namespace hw08_10_25
{
    void main() {
        Stop stop1(600000, 10000, 60000, 20, StopType::Regular);

        stop1.run();
        stop1.printResult();

        Stop stop2(3600000, 10000, 60000, 20, StopType::Regular);

        stop2.run();
        stop2.printResult();
    }
}