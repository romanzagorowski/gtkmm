#pragma once

#include <cstdint>

struct R
{
    R(std::uint64_t time, double open, double high, double low, double close, std::uint64_t volume) :
        time{time}, open{open}, high{high}, low{low}, close{close}, volume{volume}
    {
    }

    std::uint64_t   time;
    double open;
    double high;
    double low;
    double close;
    std::uint64_t   volume;
};
