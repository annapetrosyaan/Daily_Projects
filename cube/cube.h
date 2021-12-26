/*Encoder-Decoder program that takes a string 
and encodes it by the key you sent*/

#pragma once
#include <iostream>
#include <string>


class Cube
{
public:
	Cube() = default;
	Cube(const Cube&) = delete;
	Cube& operator=(const Cube&) = delete;
public:
	void set_str(std::string, std::string);
	std::string get_str() const;
	std::string encode();
	std::string decode();
private:
	const int cube_size = 8;
	std::string str;
	std::string key;
	void to_up();
	void to_down();
	void to_left();
	void to_right();
};

