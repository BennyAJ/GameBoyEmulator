#ifndef CPU_H
#define CPU_H

#include <array>

// Mostly based on these docs http://www.zilog.com/docs/z80/um0080.pdf
// Some adjustments based on these docs: http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf
// Naming conventions correspond to the Z80 Docs
struct CPU {
  // Program Counter
  uint16_t pc;

  // Stack Pointer
  uint16_t sp;

  // Index Registers
  uint16_t ix;
  uint16_t iy;

  // Interrupt Page Address Register
  char i;

  // Memory Refresh Register
  char r;

  // There are 6 general purpose 8 bit registers in the first set, ordered B C D E H L
  std::array<char, 6> general_purpose;

  // There are 6 general purpose 8 bit registers in the second set, ordered B' C' D' E' H' L'
  std::array<char, 6> general_purpose_alt;

  // Main accumulator register + corresponding flag register
  char accumulator;
  char flags;

  // Alternate accumulator register + corresponding flag register
  char accumulator_alt;
  char flags_alt;
};

#endif
