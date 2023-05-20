#include <iostream>
#include <math.h>
#include "Figure.h"

class Triangle : protected Figure 
{
public:
	Triangle();
	Triangle(double firstSide);

	double getFirstSide();
	void setFirstSide(double firstSide);

	double Area();
	double Perimeter();
};

Triangle::Triangle() {}

Triangle::Triangle(double firstSide): Figure(firstSide) {}

double Triangle::getFirstSide()
{
    return Figure::getSideLength(); 
}

void Triangle::setFirstSide(double FirstSide) 
{ 
    Figure::setSideLength(FirstSide); 
}

double Triangle::Area() 
{
	return pow(sideLength, 2) * sqrt(3) / 4;
}

double Triangle::Perimeter() 
{ 
    return 3 * sideLength;
}