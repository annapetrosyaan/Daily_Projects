#pragma once
#include <iostream>
#include <string>
#include <vector>
class Student {
private:
	char name[20]{};
	char surname[40]{};
public:
	void set_name(char*);
	void set_surname(char*);
	char* getname();
	char* getsurname();
};