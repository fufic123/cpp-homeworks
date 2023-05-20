#include "Figure.h"
#include <math.h>
#define PI acos(-1.0)

class Circle : protected Figure {
public:
	Circle();
	Circle(double diameter);

	double getDiameter();

	void setDiameter(double diameter);

	double Area();
	double Perimeter();
};

Circle::Circle() {}

Circle::Circle(double diameter): Figure(diameter) {}

double Circle::getDiameter() 
{
    return Figure::getSideLength(); 
}

void Circle::setDiameter(double diameter) 
{ 
    Figure::setSideLength(diameter); 
}

double Circle::Area() 
{ 
	return (PI * pow(sideLength, 2)) / 4;
}

double Circle::Perimeter() 
{
	return PI * sideLength;
}

