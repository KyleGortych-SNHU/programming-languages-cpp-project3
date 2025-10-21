#include "ProduceFrequency.h"
#include <iostream>
#include <exception>

using namespace std;

int main () {
  // adding a try catch exception for future implemented throw
  try {
    ProduceFrequency pf;
    pf.RunMenu();
  } catch(const exception& e) {
    cerr << "iostream error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}
