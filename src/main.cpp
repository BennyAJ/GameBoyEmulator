#include <iostream>

#include "memory.h"

using namespace std;

int main(int /*argc*/, char* /*argv*/[]) {

  int test[50];

  test[52] = 3;

  int *ptr = new int;

  cout << "Hello World!" << endl;
  return 5.0;
}
