#ifndef VCIPHER_H
#define VCIPHER_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>


class VCipher {
private:
  std::string m_key, m_text;
  void CleanString();

public:
  VCipher(std::string text);
  std::string Encryptor(std::string key);
  std::string Decryptor(std::string key);
};


#endif
