#include "executive.h"

executive::~executive(){
    delete m_cipher;
}

executive::executive(std::string ciphertext, std::string keyLength, std::string firstWordLength){
    m_ciphertext        = ciphertext;
    m_keyLength         = stoi(keyLength);
    m_firstWordLength   = stoi(firstWordLength);
    m_cipher            = new VCipher(m_ciphertext);
    Alphabet();
    Dictionary();
    StringGenerator(m_alphabet, m_keyLength, 26);
}

void executive::run(){
    clock_t t = clock();

    for(auto iter = m_possibleKeys.begin() ; iter != m_possibleKeys.end() ; iter++){
        std::string entirePlaintext = m_cipher->Decryptor(*iter);
        std::string plaintext = entirePlaintext.substr(0, m_firstWordLength);

        if(m_dictionary.find(plaintext) != m_dictionary.end()){
            m_hashTable[*iter] = entirePlaintext;
        }
    }

    t = clock() - t;
    float m_time = ((float) t) / CLOCKS_PER_SEC;

    std::cout << "Time it took to crack the code: " << m_time << " seconds" << std::endl;

    for(auto iter : m_hashTable) {
        std::cout << "The key used: " << iter.first << std::endl;
        std::cout << "Decrypted text: " << iter.second << std::endl;
    }
}

void executive::Alphabet(){
    for(auto i = 0 ; i < 26 ; i++){
        m_alphabet[i] = 'A' + i;
    }
}

void executive::Dictionary(){
    std::ifstream inFile("dict.txt");
    std::string input;
    while(inFile >> input){
        if(input.size() == m_firstWordLength)
            m_dictionary.insert(input);
    }
}

void executive::StringGenerator(char alphabet[], int k, int n){
    GeneratorHelper(alphabet, "", n, k);
}

void executive::GeneratorHelper(char alphabet[], std::string prefix, int n, int k){
    if(k == 0) {
        m_possibleKeys.insert(prefix);
        return;
    }
    for(auto i = 0 ; i < n ; i++) {
        std::string newPrefix;
        newPrefix = prefix + alphabet[i];
        GeneratorHelper(alphabet, newPrefix, n, k-1);
    }
}
