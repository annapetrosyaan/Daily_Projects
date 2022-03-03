#ifndef _CIPHER_H_
#define _CIPHER_H_

#include <iostream>
#include <fstream>
#include <string>

class Cipher 
{
public:
   Cipher() = default;
   Cipher(const Cipher&) = delete;
   Cipher& operator=(const Cipher&) = delete;
   ~Cipher() = default;
public:
   void encode() noexcept;
   void decode() noexcept;
private:
   std::ofstream write;
   std::ifstream read;
   std::string encText;
   std::string decText;
};

#endif // !_CIPHER_H_