#include "cube.h"



void Cube::set_str(std::string s, std::string k)
{
	str = s;
	key = k;
}

std::string Cube::get_str() const { return str; }

void Cube::to_up()
{
	std::string tmp(cube_size, ' ');
	tmp[0] = str[2];
	tmp[1] = str[3];
	tmp[2] = str[6];
	tmp[3] = str[7];
	tmp[4] = str[0];
	tmp[5] = str[1];
	tmp[6] = str[4];
	tmp[7] = str[5];
	str = tmp;
}

void Cube::to_left()
{
	std::string tmp(cube_size, ' ');
	tmp[0] = str[1];
	tmp[1] = str[5];
	tmp[2] = str[3];
	tmp[3] = str[7];
	tmp[4] = str[0];
	tmp[5] = str[4];
	tmp[6] = str[2];
	tmp[7] = str[6];
	str = tmp;
}

void Cube::to_down()
{
	std::string tmp(cube_size, ' ');
	tmp[0] = str[4];
	tmp[1] = str[5];
	tmp[2] = str[0];
	tmp[3] = str[1];
	tmp[4] = str[6];
	tmp[5] = str[7];
	tmp[6] = str[2];
	tmp[7] = str[3];
	str = tmp;
}

void Cube::to_right()
{
	std::string tmp(cube_size, ' ');
	tmp[0] = str[4];
	tmp[1] = str[0];
	tmp[2] = str[6];
	tmp[3] = str[2];
	tmp[4] = str[5];
	tmp[5] = str[1];
	tmp[6] = str[7];
	tmp[7] = str[3];
	str = tmp;
}

std::string Cube::encode()
{
	for (int i = 0; i < key.size(); ++i)
	{
		if (key[i] == 'L') { to_left(); }
		if (key[i] == 'U') { to_up(); }
		if (key[i] == 'D') { to_down(); }
		if (key[i] == 'R') { to_right(); }
	}
	return str;
}


std::string Cube::decode()
{
	for (int i = str.size() - 1; i > 0; --i)
	{
		str += str[i];
	}
	for (int i = 0; i < key.size(); ++i)
	{
		if (key[i] == 'L') { to_right(); }
		if (key[i] == 'U') { to_down(); }
		if (key[i] == 'D') { to_up(); }
		if (key[i] == 'R') { to_left(); }
	}
	return str;
}
