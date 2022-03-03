#include "cipher.h"

void Cipher::encode() noexcept
{
   read.open("text.txt");
   write.open("generateText.txt");
   if(!read.is_open()) { return; }
   while(!read.eof())
   {
       
       std::getline(read,encText);
       for(int i = 0; i < encText.size(); ++i)
       {
           if(encText[i] == ' '){ continue; }
            encText[i] = encText[i] - 3;
            if(encText[i] < 'A'){
                encText[i] = encText[i] + 'z' - 'a' + 1;
            }
       }
     write << encText;
   }
   write << std::endl;
   write.close();
   read.close();
}

void Cipher::decode() noexcept
{
   read.open("generateText.txt");
   write.open("text.txt");
   while(!read.eof())
   {
       
     std::getline(read,decText);
     for(int i = 0; i < decText.size(); ++i)
     {
           if(decText[i] == ' '){ continue; }
           decText[i] = decText[i] + 3;
           if(decText[i] > 'z'){
           decText[i] = decText[i] - 'z' + 'a' + 1;
      }
     }
   write << decText ;
   }
   write << std::endl;
   write.close();
   read.close();
}

int main()
{
    Cipher obj;
    obj.encode();
}