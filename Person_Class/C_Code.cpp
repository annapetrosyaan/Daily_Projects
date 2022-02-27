#include <iostream>
struct person 
{
     char name[40];
	int age;
};

void def_ctor(person* obj) 
{
	obj->age=0;
	obj->name[40] = {};
}

void setage(person* obj, int x) 
{
	if (x > 0) { obj->age = x; }
}

void setname(person* obj, char* ch) 
{
	if (strlen(ch) < strlen(obj->name))
	{
		for (int i = 0; i < strlen(obj->name); ++i) 
		{
			obj->name[i] = ch[i];
		}
	}
}

void parametric_ctor(person* obj, char* ch, int year) 
{
	obj->age = year;
	for (int i = 0; i < strlen(obj->name); ++i)
	{
		obj->name[i] = ch[i];
	}
}


person copy_ctor(person* obj, person* obj2)
{
	obj -> age= obj2 -> age;
	for (int i = 0; i < strlen(obj2->name); ++i)
	{
		obj->name[i] = obj2->name[i];
	}
	return *obj;
} 
