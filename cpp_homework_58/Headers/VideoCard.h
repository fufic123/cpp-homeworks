#include <iostream>
using namespace std;

class VideoCard {
private:
	string name;
	int number;

public:
	VideoCard() {
		name = "Nvidia GeForce";
		number = 3060;
	}

	VideoCard(string name, int number) {
		this->name = name;
		this->number = number;
	}

	void Show() 
	{ 
		cout << "Name: " << name << number << "\n"; 
	}
};

