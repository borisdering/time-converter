#include "industrial_time.h"

double standard_to_industrial(uint64_t hours, uint64_t minutes) {
    static_assert(sizeof(uint64_t) >= sizeof(uint16_t), "uint64_t is not large enough to hold uint16_t");
    if (minutes >= 60) {
        throw std::invalid_argument("Minutes must be less than 60");
    }
    return hours + (minutes / 60.0);
}

void industrial_to_standard(double industrial_time, uint16_t &hours, uint16_t &minutes) {
    hours = static_cast<uint16_t>(industrial_time);
    minutes = static_cast<uint16_t>((industrial_time - hours) * 60);
}