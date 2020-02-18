#include "VCipher.h"

std::string VCipher::Encryptor(std::string text){
  return text;
}

std::string VCipher::Decryptor(std::string text, std::string key){
  std::string plaintext;
  for (size_t i = 0; i < text.length(); i++) {
    int x = (text[i] - key[i] +26) % 26;
    x += 'A';
    plaintext.push_back(x);
  }
  return plaintext;
}
