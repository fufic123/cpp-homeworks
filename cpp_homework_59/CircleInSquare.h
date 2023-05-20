#include "Circle.h"
#include "Square.h"
#include <math.h>
#define PI acos(-1.0)

class CircleInSquare : protected Circle, protected Square {
private:
    double side;

public:
	CircleInSquare();
	CircleInSquare(double value);

	double CircleArea();
	double CirclePerimeter();

	double SquareArea();
	double SquarePerimeter();

	double AreaOutsideCircle();
};

CircleInSquare::CircleInSquare() {}

CircleInSquare::CircleInSquare(double value) : Circle(value), Square(value) {}

double CircleInSquare::CircleArea() 
{ 
    return (PI * pow(Circle::getDiameter(), 2)) / 4;
}

double CircleInSquare::CirclePerimeter() 
{ 
    return 2 * PI * (Circle::getDiameter() / 2); 
}

double CircleInSquare::SquareArea() 
{ 
    return pow(Circle::getDiameter(), 2); 
}

double CircleInSquare::SquarePerimeter() 
{ 
    return 4 * Circle::getDiameter(); 
}

double CircleInSquare::AreaOutsideCircle() 
{ 
    return SquareArea() - CircleArea();
}