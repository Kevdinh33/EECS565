#ifndef VCIPHER_H
#define VCIPHER_H
#include <string>


class VCipher {
private:

public:

  std::string Encryptor(std::string text);
  std::string Decryptor(std::string text, std::string key);

};


#endif
