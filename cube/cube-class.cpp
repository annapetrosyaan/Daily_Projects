#include "cube.h"

#include <iostream>
#include <string>

int main()
{
	std::string word;
	std::string enc;
	Cube obj;
	std::cout << "Enter the word"<<std::endl;
	std::cin >> word;
	std::cout << "Set the key to encode L-left,R-right,U-up,D-down"<<std::endl;
	std::cin >> enc;
	obj.set_str(word, enc);
	std::string s = obj.encode();
	std::string s1= obj.decode();
	std::cout <<"Encoded word: "<< s <<std::endl;
	std::cout << "Decoded word: " << s1;
}