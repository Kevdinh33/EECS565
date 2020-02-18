#include "VCipher.h"

VCipher::VCipher(std::string text) {
    m_text = text;
    CleanString();
}

void VCipher::CleanString() {
    m_text.erase(std::remove(m_text.begin(), m_text.end(), ' '), m_text.end());
    for(auto &c : m_text)
        c = toupper(c);
}

std::string VCipher::Encryptor(std::string key) {
    size_t keySize = key.length();
    size_t pos = 0;
    std::string temp = m_text;
    for(size_t i = 0 ; i < temp.length() ; i++) {
        if(pos >= keySize)
            pos = 0;
        temp[i] = 'A' + (( (temp[i] - 65) + (key[pos] - 65) ) % 26 );
        pos++;
    }
    return temp;
}

std::string VCipher::Decryptor(std::string key) {
    size_t keySize = key.length();
    size_t pos = 0;
    std::string temp = m_text;
    for(size_t i = 0 ; i < temp.length() ; i++) {
        if(pos >= keySize)
            pos = 0;
        temp[i] = 'A' + (( (temp[i]) - (key[pos]) + 26) % 26) ;
        pos++;
    }
    return temp;
}
