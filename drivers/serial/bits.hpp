#ifndef AQ_DRIVERS_SERIAL_BITS_HPP_
#define AQ_DRIVERS_SERIAL_BITS_HPP_
#include <aq/types.hpp>

namespace aq { namespace serial { namespace brr {
#if defined(AQ_CLOCK_20M)
constexpr uint8_t default_brr = 64;
#elif defined(AQ_CLOCK_25M)
constexpr uint8_t default_brr = 80;
#else
#error no setting clock.
#endif
}}}

namespace aq { namespace serial { namespace ssr {
constexpr uint8_t tdre = 1 << 7;
constexpr uint8_t rdrf = 1 << 6;
}}}

namespace aq { namespace serial { namespace scr {
constexpr uint8_t tie = 1 << 7;
constexpr uint8_t rie = 1 << 6;
constexpr uint8_t te = 1 << 5;
constexpr uint8_t re = 1 << 4;
}}}

#endif
