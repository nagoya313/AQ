#include <aq/types.hpp>
#include <aq/drivers/dram.hpp>
#include <aq/h8/memory_map.h>
#include "regs.hpp"

namespace aq { namespace dram { namespace {
constexpr auto start = reinterpret_cast<uint32_t *>(AQ_DRAM_START);
constexpr auto end = reinterpret_cast<uint32_t *>(AQ_DRAM_END);

union value_t {
  uint8_t val8[4];
  uint16_t val16[2];
  uint32_t val32[1];
};

bool read_check_value(const volatile value_t &p,
                      const volatile value_t &r) {
  volatile value_t rval;  
  rval.val8[0] = p.val8[0];
  rval.val8[1] = p.val8[1];
  rval.val8[2] = p.val8[2];
  rval.val8[3] = p.val8[3];
  if (rval.val32[0] != r.val32[0]) {
    return false;
  }
  rval.val16[0] = p.val16[0];
  rval.val16[1] = p.val16[1];
  if (rval.val32[0] != r.val32[0]) {
    return false;
  }
  rval.val32[0] = p.val32[0];
  if (rval.val32[0] != r.val32[0]) {
    return false;
  }
  return true;
}

bool check_value(volatile value_t &p, 
                 const volatile value_t &wval) {
  volatile value_t rval;  
  p.val8[0] = wval.val8[0];
  p.val8[1] = wval.val8[1];
  p.val8[2] = wval.val8[2];
  p.val8[3] = wval.val8[3];
  rval.val8[0] = p.val8[0];
  rval.val8[1] = p.val8[1];
  rval.val8[2] = p.val8[2];
  rval.val8[3] = p.val8[3];
  if (rval.val32[0] != wval.val32[0]) {
    return false;
  }
  p.val16[0] = wval.val16[0];
  p.val16[1] = wval.val16[1];
  rval.val16[0] = p.val16[0];
  rval.val16[1] = p.val16[1];
  if (rval.val32[0] != wval.val32[0]) {
    return false;
  }
  p.val32[0] = wval.val32[0];
  rval.val32[0] = p.val32[0];
  if (rval.val32[0] != wval.val32[0]) {
    return false;
  }
  return true;
}
}}}

namespace aq { namespace dram {
void init() {
  *abwcr = 0xff;
  *rtcor = 0x03;
  *rtmcsr = 0x37;
  *drcrb = 0x98;
  *drcra = 0x30;
  *p1ddr = 0xff;
  *p2ddr = 0x07;
  *p8ddr = 0x04;
  *wcrl = 0xcf;
  *astcr = 0xfb;
}

void clear() {
  for (auto p = start; p < end; ++p) {
    *p = 0;
  }
}

uintptr_t check() {
  for (uint32_t *p = start; p < end; ++p) {
    volatile value_t v;
    v.val32[0] = reinterpret_cast<uint32_t>(p);
    if (!check_value(*reinterpret_cast<volatile value_t *>(p), v)) {
      return reinterpret_cast<uintptr_t>(p);
    }
    v.val32[0] = 0;
    if (!check_value(*reinterpret_cast<volatile value_t *>(p), v)) {
      return reinterpret_cast<uintptr_t>(p);
    }
    v.val32[0] = 0xffffffff;
    if (!check_value(*reinterpret_cast<volatile value_t *>(p), v)) {
      return reinterpret_cast<uintptr_t>(p);
    }
  }
  for (uint32_t *p = start; p < end; ++p) {
    volatile value_t v;
    v.val32[0] = 0xffffffff;
    if (!read_check_value(*reinterpret_cast<volatile value_t *>(p), v)) {
      return reinterpret_cast<uintptr_t>(p);
    }
  }
  return 0;
}
}}
