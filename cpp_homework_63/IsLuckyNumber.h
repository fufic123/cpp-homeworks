#include <iostream>
using namespace std;

bool isLuckyNumber(int number) {
	if (number < 100000)
	{ 
		throw "Too small";
	}
	else if (number > 999999) 
	{
		throw exception("Too big");
	}
	else { 
		return (number / 100000 + number / 10000 % 10 + number / 1000 % 10) == 
		(number / 100 % 10 + number / 10 % 10 + number % 10);
	};
}