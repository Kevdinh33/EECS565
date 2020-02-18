#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <time.h>

#include "VCipher.h"

class executive {

private:
    char m_alphabet[26];
    std::string m_ciphertext;
    int m_keyLength;
    unsigned int m_firstWordLength;
    VCipher* m_cipher;
    std::unordered_map<std::string, std::string> m_hashTable;
    std::unordered_set<std::string> m_possibleKeys;
    std::unordered_set<std::string> m_dictionary;

    void Alphabet();
    void StringGenerator(char set[], int k, int n);
    void GeneratorHelper(char set[], std::string prefix, int n, int k);
    void Dictionary();

public:
    executive(std::string ciphertext, std::string keyLength, std::string firstWordLength);
    ~executive();
    void run();
};

#endif
