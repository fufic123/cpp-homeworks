#include <iostream>
#include <limits>
using namespace std;

class Fraction 
{
private:
	int numerator;
	int denominator;

public:
	Fraction();
	Fraction(int numerator, int denominator);
    void Reduction();

    Fraction operator+(Fraction b);
    Fraction operator-(Fraction b);
    Fraction operator+(float b);
    Fraction operator-(float b);
    Fraction operator*(Fraction b);
    Fraction operator*(float b);
    Fraction& operator++();
    Fraction& operator--();
    Fraction operator++(int);
    Fraction operator--(int);

    void setNumerator(int numerator);
    void setDenominator(int denominator);
    float getNumerator() const;
    float getDenominator() const;
};

ostream& operator << (ostream& o, const Fraction& p);


Fraction::Fraction(): numerator(1), denominator(1) {}
Fraction::Fraction(int numerator, int denominator) 
{
	if (denominator == 0) 
	{
		this->numerator = numeric_limits<int>::max();
		this->denominator = 1;
	}
	else 
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
}

void Fraction::Reduction() 
{
	for (int i = denominator; i >= 1; i--) 
	{
		if (numerator % i == 0 && denominator % i == 0) 
		{
			int numerator_res = numerator / i;
			int denominator_res = denominator / i;
			numerator = numerator_res;
			denominator = denominator_res;
		}
	}
}

Fraction Fraction::operator + (Fraction b) 
{
	int first = (numerator * b.denominator) + (denominator * b.numerator);
	int second = denominator * b.denominator;
	Fraction res(first, second);
	res.Reduction();
	return res;
}

Fraction Fraction::operator - (Fraction b) 
{ 
	int first = (numerator * b.denominator) - (denominator * b.numerator);
	int second = denominator * b.denominator;
	Fraction res(first, second);
	res.Reduction();
	return res;
}

Fraction Fraction::operator + (float b) 
{ 
	float first = (float)numerator + ((float)denominator * b);
	while (first - (int)first > 0) 
	{
		first *= 10;
		denominator *= 10;
	}
	Fraction res(first, denominator);
	res.Reduction();
	return res;
}

Fraction Fraction::operator - (float b) 
{ 
	float first = (float)numerator - ((float)denominator * b);
	while (first - (int)first > 0) 
	{
		first *= 10;
		denominator *= 10;
	}
	Fraction res(first, denominator);
	res.Reduction();
	return res;
}

Fraction Fraction::operator * (Fraction b) 
{ 
	Fraction res(numerator * b.numerator, denominator * b.denominator);
	res.Reduction();
	return res; 
}

Fraction Fraction::operator * (float b) 
{ 
	float first = numerator * b;
	while (first - (int)first > 0) 
	{
		first *= 10;
		denominator *= 10;
	}
	Fraction res(first, denominator);
	res.Reduction();
	return res;
}

Fraction& Fraction::operator ++ () 
{
	numerator += denominator;
	return *this;
}

Fraction& Fraction::operator -- () 
{
	numerator -= denominator;
	return *this;
}

Fraction Fraction::operator ++ (int) 
{
	Fraction tmp(numerator, denominator);
	numerator += denominator;
	return tmp;
}

Fraction Fraction::operator -- (int) 
{
	Fraction tmp(numerator, denominator);
	numerator -= denominator;
	return tmp;
}

float Fraction::getNumerator() const 
{ 
	return numerator; 
}

float Fraction::getDenominator() const 
{ 
	return denominator; 
}

void Fraction::setNumerator(int numerator) 
{ 
	this->numerator = numerator; 
}

void Fraction::setDenominator(int denominator) 
{ 
	this->denominator = denominator; 
}

ostream& operator << (ostream& o, const Fraction& p) 
{
	o << p.getNumerator() << "/" << p.getDenominator();
	return o;
}