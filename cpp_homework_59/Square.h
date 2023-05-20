
#include <iostream>
#include <math.h>
#include "Figure.h"

class Square : protected Figure 
{  
public:
	Square();
	Square(double firstSide);

	double getFirstSide();
	void setFirstSide(double firstSide);

	double Area();
	double Perimeter();
};

Square::Square() {}
Square::Square(double firstSide) : Figure(firstSide) {}

double Square::getFirstSide() 
{ 
    return Figure::getSideLength(); 
}

void Square::setFirstSide(double firstSide) 
{ 
    Figure::setSideLength(firstSide); 
}

double Square::Area() 
{
	return pow(sideLength, 2);
}

double Square::Perimeter() 
{
	return 4 * sideLength;
}