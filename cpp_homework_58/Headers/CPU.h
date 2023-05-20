#include <iostream>
using namespace std;

class CPU {
private:
	string name;
	float ghz;

public:
	CPU() {
		name = "Intel";
		ghz = 0.4;
	}

	CPU(string name, float ghz) {
		this->name = name;
		this->ghz = ghz;
	}

	void Show() 
	{
		cout << "Name: " << name << "\n" << "GHz: " << ghz << "\n"; 
	}
};
