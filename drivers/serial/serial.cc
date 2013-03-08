#include <aq/drivers/serial.hpp>
#include "bits.hpp"
#include "regs.hpp"

namespace aq { namespace serial {
void init(id_t id) {
  scis[static_cast<int>(id)]->scr = 0;
  scis[static_cast<int>(id)]->smr = 0;
  scis[static_cast<int>(id)]->brr = brr::default_brr;
  scis[static_cast<int>(id)]->scr = scr::te | scr::re; 
  scis[static_cast<int>(id)]->ssr = 0;
}

bool is_send_enable(id_t id) {
  return scis[static_cast<int>(id)]->ssr & ssr::tdre;
}

bool send_byte(id_t id, uint8_t c) {
  while (!is_send_enable(id));
  scis[static_cast<int>(id)]->tdr = c;
  scis[static_cast<int>(id)]->ssr &= ~ssr::tdre;
  return true;
}

bool is_receive_enable(id_t id) {
  return scis[static_cast<int>(id)]->ssr & ssr::rdrf;
}

uint8_t receive_byte(id_t id) {
  while (!is_receive_enable(id));
  const auto c = scis[static_cast<int>(id)]->rdr;
  scis[static_cast<int>(id)]->ssr &= ~ssr::rdrf;
  return c;
}

bool is_interrupt_send_enable(id_t id) {
  return scis[static_cast<int>(id)]->scr & scr::tie;
}

void interrupt_send_set_enable(id_t id) {
  scis[static_cast<int>(id)]->scr |= scr::tie;
}

void interrupt_send_set_disable(id_t id) {
  scis[static_cast<int>(id)]->scr &= ~scr::tie;
}

bool is_interrupt_receive_enable(id_t id) {
  return scis[static_cast<int>(id)]->scr & scr::rie;
}

void interrupt_receive_set_enable(id_t id) {
  scis[static_cast<int>(id)]->scr |= scr::rie;
}

void interrupt_receive_set_disable(id_t id) {
  scis[static_cast<int>(id)]->scr &= ~scr::rie;
}
}}

