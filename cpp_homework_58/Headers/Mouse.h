#include <iostream>
using namespace std;

class Mouse 
{
private:
	string name;

public:
	Mouse() {
		name = "Bloody";
	}

	Mouse(string name) {
		this->name = name;
	}

	void Show() 
	{ 
		cout << "Name: " << name << "\n";
	}
};
