#ifndef AQ_DRIVERS_SERIAL_HPP_
#define AQ_DRIVERS_SERIAL_HPP_
#include <aq/types.hpp>

namespace aq { namespace serial {
enum class id_t {
  device0 = 0,
  device1 = 1,
  device2 = 2,
  default_device = device1
};

void init(id_t id);
bool is_send_enable(id_t id);
bool send_byte(id_t id, uint8_t c);
bool is_receive_enable(id_t id);
uint8_t receive_byte(id_t id);
bool is_interrupt_send_enable(id_t id);
void interrupt_send_set_enable(id_t id);
void interrupt_send_set_disable(id_t id);
bool is_interrupt_receive_enable(id_t id);
void interrupt_receive_set_enable(id_t id);
void interrupt_receive_set_disable(id_t id);
void putc(uint8_t c);
void puts(const char *str);
void putxval(uint32_t v, size_t column);
void putval(uint16_t v, size_t column);
uint8_t getc();
size_t gets(char *buf, size_t s);
}}

#endif
