#include <iostream>
#include <string>
#include <math.h>
class Planet {
private:
	std::string name;
	double distance;
	long radius;
	long double mass;
	

public:
	void setname(std::string str) { name = str; }
	void setdistance(double her) { distance = her; }
	void setradius(long double name) { radius = name; }
	void setmass(long double zang) { mass = zang; }
	std::string getname() { return name; }
	double getdis() { return distance; }
	long double getmass() { return mass; }
	 long double getradius() { return radius; }
	double getank() {
		long double gravity{};
		long rad = getradius();
		long raduises = radius * rad;
		gravity = 0.0000000000667 * mass / raduises;
		return gravity;
	}
	

};

void start() {
	Planet obj;
	std::string hname;
	double hdistance;
	long  double hradius;
	long double hmass;
	std::cout << "enter name:";
	std::cin >> hname;
	std::cout << "enter distance:";
	std::cin >> hdistance;
	std::cout << "enter radius:";
	std::cin >> hradius;
	std::cout << "enter mass:";
	std::cin >> hmass;
	std::cout << std::endl;
	obj.setname(hname);
	obj.setdistance(hdistance);
	obj.setradius(hradius);
	obj.setmass(hmass);
	std::cout << obj.getname() << "'s  gravity is= " << obj.getank();
}

int main() {
	start();
}


