#ifndef MEMORY_H
#define MEMORY_H

#include <array>

struct Memory {
  std::array<uint8_t, 8192> ram;
  std::array<uint8_t, 8192> vram;
};

#endif
