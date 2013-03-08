#include <aq/types.hpp>
#include <aq/drivers/serial.hpp>

namespace aq { namespace serial {
void putc(uint8_t c) {
  if (c == '\n') {
    send_byte(id_t::default_device, '\r');
  }
  send_byte(id_t::default_device, c);
}

void puts(const char *str) {
  while (*str) {
    putc(*(str++));
  }
}

void putxval(uint32_t v, size_t column) {
  char buffer[9];
  char *p = buffer + sizeof(buffer) - 1;
  (*p--) = '\0';  
  if (!v && !column) {
    ++column;
  }
  while (v || column) {
    *(p--) = "0123456789abcdef"[v & 0xf];
    v >>= 4;
    if (column) {
      --column;
    }
  }
  puts(p + 1);
}

void putval(uint16_t v, size_t column) {
  char buffer[6];
  char *p = buffer + sizeof(buffer) - 1;
  (*p--) = '\0';  
  if (!v && !column) {
    ++column;
  }
  while (v || column) {
    *(p--) = "0123456789"[v & 10];
    v /= 10;
    if (column) {
      --column;
    }
  }
  puts(p + 1);
}

uint8_t getc() {
  auto c = receive_byte(id_t::default_device);
  c = (c == '\r') ? '\n' : c;
  putc(c);
  return c;
}

size_t gets(char *buf, size_t s) {
  size_t i = 0;
  uint8_t c;
  do {
    c = getc();
    if (c == '\n') {
      c = '\0';
    }
    buf[i++] = c;
  } while (i < s && c);
  return i - 1;
}
}}
