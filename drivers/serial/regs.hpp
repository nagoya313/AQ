#ifndef AQ_DRIVERS_SERIAL_REGS_HPP_
#define AQ_DRIVERS_SERIAL_REGS_HPP_
#include <aq/types.hpp>

namespace aq { namespace serial {
constexpr volatile struct registers_t {
  register8_t smr;
  register8_t brr;
  register8_t scr;
  register8_t tdr;  
  register8_t ssr;   
  register8_t rdr;
  register8_t scmr;
} *scis[] = {
  reinterpret_cast<volatile registers_t *>(0xffffb0),
  reinterpret_cast<volatile registers_t *>(0xffffb8),
  reinterpret_cast<volatile registers_t *>(0xffffc0)
};
}}

#endif

