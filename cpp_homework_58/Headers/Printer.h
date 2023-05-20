#include <iostream>
using namespace std;

class Printer {
private:
	string name;
	string color;

public:
	Printer() {
		name = "Canon";
		color = "black";
	}

	Printer(string name, string color) {
		this->name = name;
		this->color = color;
	}

	void Show() 
	{ 
		cout << "Name: " << name << "\n"; 
		cout << "Color: " << color << "\n"; 
	}
};