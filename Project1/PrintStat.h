#pragma once

#include "mystd.h"

namespace hw04_10_25
{
    struct PrintStat {
        String user;
        String document;
        String time;

        friend ostream& operator<<(ostream& os, const PrintStat& ps) {
            os << ps.time << " | " << ps.user << " надрукував " << ps.document;
            return os;
        }
    };
}
