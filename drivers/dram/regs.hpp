#ifndef AQ_DRIVERS_DRAM_REGS_HPP_
#define AQ_DRIVERS_DRAM_REGS_HPP_
#include <aq/types.hpp>

namespace aq { namespace dram {
constexpr auto p1ddr  = reinterpret_cast<register8_t *>(0xfee000);
constexpr auto p2ddr  = reinterpret_cast<register8_t *>(0xfee001);
constexpr auto p8ddr  = reinterpret_cast<register8_t *>(0xfee007);

constexpr auto abwcr  = reinterpret_cast<register8_t *>(0xfee020);
constexpr auto astcr  = reinterpret_cast<register8_t *>(0xfee021);
constexpr auto wcrl   = reinterpret_cast<register8_t *>(0xfee023);
constexpr auto drcra  = reinterpret_cast<register8_t *>(0xfee026);
constexpr auto drcrb  = reinterpret_cast<register8_t *>(0xfee027);
constexpr auto rtmcsr = reinterpret_cast<register8_t *>(0xfee028);
constexpr auto rtcor  = reinterpret_cast<register8_t *>(0xfee02a);
}}

#endif

