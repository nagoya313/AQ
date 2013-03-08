#ifndef AQ_BOOTLOADER_MEMORY_HPP_
#define AQ_BOOTLOADER_MEMORY_HPP_
#include <aq/types.hpp>

namespace aq { namespace memory {
void *set(void *b, int c, size_t len);
void *copy(void *dst, const void *src, size_t len);
int compare(const void *lhs, const void *rhs, size_t len);
}}

#endif

