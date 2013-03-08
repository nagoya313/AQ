#ifndef AQ_TYPES_HPP_
#define AQ_TYPES_HPP_

namespace aq {
using int8_t = signed char;
using uint8_t = unsigned char;
using int16_t = short;
using uint16_t = unsigned short;
using int32_t = long;
using uint32_t = unsigned long;
using size_t = decltype(sizeof(0));
using nullptr_t = decltype(nullptr);
using intptr_t = long;
using uintptr_t = unsigned long;
using register8_t = volatile uint8_t;
}

#endif
