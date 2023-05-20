#include <iostream>
using namespace std;

class RAM {
private:
	string name;
	int memory;

public:
	RAM() {
		name = "Kingston";
		memory = 8;
	}

	RAM(string name, int memory) {
		this->name = name;
		this->memory = memory;
	}

	void Show() 
	{ 
		cout << "Name: " << name << "\n" << "Memory: " << memory << "\n"; 
	}
};