#include <iostream>
#include <fstream>

#include "cpu.h"
#include "memory.h"

using namespace std;

int main(int /*argc*/, char* /*argv*/[]) {
  CPU cpu;
  std::array<char, 0xFFFF> memory;

  ifstream rom("/home/benny/Programming/GameBoyEmulator/thirdparty/gb-test-roms/cpu_instrs/cpu_instrs.gb", ifstream::binary);

  cout << "Loaded ROM" << endl;
  cout << "ROM Good: " << rom.good() << endl;
  char byte;

  rom.read(memory.data(), 0x8000);

  if (rom.eof()) {
    cerr << "EOF bit triggered while trying to read ROM. Exiting" << endl;
    exit(1);
  }
  else if (rom.fail()) {
    cerr << "Fail bit triggered while trying to read ROM. Exiting" << endl;
    exit(1);
  }
  else if (rom.bad()) {
    cerr << "Bad bit triggered while trying to read ROM. Exiting" << endl;
    exit(1);
  }
  


  return 0;
}
