#include "memory.hpp"

extern "C" {
void *memset(void *b, int c, aq::size_t len) {
  char *p = static_cast<char *>(b);
  const char *t = p + len;
  while (p != t) {
    *(p++) = c;
  }
  return b;
}

void *memcpy(void *dst, const void *src, aq::size_t len) {
  char *d = static_cast<char *>(dst);
  const char *s = static_cast<const char *>(src);
  const char *t = s + len;
  while (s != t) {
    *(d++) = *(s++);
  }
  return dst;
}
}

namespace aq { namespace memory {
void *set(void *b, int c, size_t len) {
  return memset(b, c, len);  
}

void *copy(void *dst, const void *src, size_t len) {
  return memcpy(dst, src, len);
}

int compare(const void *lhs, const void *rhs, size_t len) {
  const char *l = static_cast<const char *>(lhs);
  const char *r = static_cast<const char *>(rhs);
  const char *t = r + len;
  while (r != t) {
    if (*l != *r) {
      return (*l > *r) ? 1 : -1;
    }
    ++l;
    ++r;
  }
  return 0;
}
}}
