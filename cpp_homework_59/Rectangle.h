
#include <iostream>
#include <math.h>
#include "Figure.h"

class Rectangle : protected Figure 
{  
private:
    double secondSide;

public:
	Rectangle();
	Rectangle(double firstSide, double secondSide);

	double getFirstSide();
    double getSecondSide();

	void setFirstSide(double firstSide);
    void setSecondSide(double secondSide);

	double Area();
	double Perimeter();
};

Rectangle::Rectangle() {}
Rectangle::Rectangle(double firstSide, double secondSide) : Figure(firstSide), secondSide(secondSide) {}

double Rectangle::getFirstSide() 
{ 
    return Figure::getSideLength(); 
}

double Rectangle::getSecondSide() 
{ 
    return secondSide;
}

void Rectangle::setFirstSide(double firstSide) 
{ 
    Figure::setSideLength(firstSide); 
}

void Rectangle::setSecondSide(double secondSide) 
{ 
    this->secondSide = secondSide;
}

double Rectangle::Area() 
{
	return (sideLength * secondSide);
}

double Rectangle::Perimeter() 
{
	return (2 * sideLength + 2 * secondSide);
}