#pragma once

#include <cstdint>

namespace mt4::hst
{

    struct header
    {
        std::int32_t    version;
        char            copyright[64];
        char            symbol[12];
        std::uint32_t   period;
        std::uint32_t   digits;
        std::uint32_t   timesign;
        std::uint32_t   last_sync;
        std::uint32_t   unused[13];
    };

    struct record_v400
    {
        std::uint32_t   ctm;
        double          open;
        double          low;
        double          high;
        double          close;
        double          volume;
    };

    struct record_v401
    {
        std::uint64_t   ctm;
        double          open;
        double          high;
        double          low;
        double          close;
        std::uint64_t   volume;
        std::uint32_t   spread;
        std::uint64_t   real_volume;
    };
}
