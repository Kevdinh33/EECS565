#include <iostream>
#include <string>
#include "VCipher.h"
#include "executive.h"

int main(int argc, char const *argv[]) {
  if(argc < 4)
        std::cout << "Incorrect number of parameters!\n";
    else
    {
        executive exec(argv[1], argv[2], argv[3]);
        exec.run();
    }
  return 0;
}
