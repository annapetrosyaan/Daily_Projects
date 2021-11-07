#include <iostream>
class Person {
private:
	std::string name;
	int age;
public:
	Person() {
		age=0;	}
	Person(std::string s,int a): name(s),age(a){}
	int getage() { return age; }
	std::string getname() { return name; }
	void setage(int a) { age = a; }
	void setname(std::string str) { name = str; }
	Person(const Person& obj) {
		age = obj.age;
		name = obj.name;
	}
	Person& operator=(const Person& obj) {
		age = obj.age;
		name = obj.name;
		return *this;
	}

};