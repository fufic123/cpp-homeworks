#include <iostream>
#include <math.h>
using namespace std;

class Figure {
protected:
	double sideLength;

public:
	Figure();
	Figure(double sideLength);

	double getSideLength();
	void setSideLength(double sideLength);

	double Area(int numberOfSides);
	double Perimeter(int numberOfSides);
};


Figure::Figure(): sideLength(0) {}

Figure::Figure(double SideLength): sideLength(sideLength) {}

double Figure::getSideLength() 
{ 
    return sideLength; 
}

void Figure::setSideLength(double sideLength) 
{ 
    this->sideLength = sideLength; 
}