#ifndef AQ_DRIVERS_DRAM_HPP_
#define AQ_DRIVERS_DRAM_HPP_
#include <aq/types.hpp>

namespace aq { namespace dram {
void init();
void clear();
uintptr_t check();
}}

#endif
