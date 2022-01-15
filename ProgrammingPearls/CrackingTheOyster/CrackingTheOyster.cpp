#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

int main()
{
	const int count{ 1000000 };
	std::fstream myfile;
	std::string road("UnsortedFile.txt"), line;

	std::bitset<count> bits; ///reserving 1 million
	myfile.open(road);

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if (line != "")
			{
				bits[std::stoi(line)] = 1;
			}
	    }
	}
	else
	{
		std::cout << "Invalid file:";
	}
	myfile.close();

	road = { "SortedFile.txt" };
	std::fstream myfile2(road,std::ios_base::out);
	for (int i = 0; i < bits.size(); ++i)
	{
		if (bits[i]) { myfile2 << i << "\n"; }
	}
	return 0;
}