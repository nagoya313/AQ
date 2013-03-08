#ifndef AQ_H8_VECTOR_HPP_
#define AQ_H8_VECTOR_HPP_
#include <aq/types.hpp>

extern "C" {
extern char soft_vector;
}

namespace aq { namespace interrupt {
//constexpr auto soft_vector_num = 64;
using handler_t = void (*)(int16_t, uint32_t);
//constexpr auto vectors = reinterpret_cast<handler_t *>(&soft_vector);
}}

#endif
