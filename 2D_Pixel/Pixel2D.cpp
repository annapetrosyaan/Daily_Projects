// Pixel2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Pixel {
private:
	int x;
	int y;
public:
	Pixel() { x = 0; y = 0; }
	Pixel(int a, int b) :x(a), y(b){}
	void setx(int a) {
		if (a > 0) {
			x = a;
		}
	}
	void sety(int b) { 
		if (b > 0)
		{ y = b; }
	}
	friend bool operator<(const Pixel&, const Pixel&);
	friend bool operator> (const Pixel& , const Pixel& );
	int getx()const { return x; }
	int gety()const { return y; }
	~Pixel(){}
};

Pixel operator+(const Pixel& obj,const Pixel& ob) {
	Pixel sum;
	sum.setx(obj.getx()+ob.getx());
	sum.sety(obj.gety() + ob.gety());
	return sum;
}
 
bool operator>(const Pixel& c1, const Pixel& c2)
{
	return c1.x > c2.x;
}
bool operator>(const Pixel& c1, const Pixel& c2)
{
	return c1.y < c2.y;
}

bool operator<(const Pixel& c1, const Pixel& c2) {
	return c1.x < c2.x;
 }

bool operator<(const Pixel& c1, const Pixel& c2)
{
	return c1.y < c2.y;
}

