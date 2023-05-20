#include <iostream>
using namespace std;

class Webcam 
{
private:
	string name;
	string quality;

public:
	Webcam() {
		name = "Logitech";
		quality = "1080p";
	}

	Webcam(string name, string quality) {
		this->name = name;
		this->quality = quality;
	}

	void Show() 
	{ 
		cout << "Name: " << name << "\n" << "Quality: " << quality << "\n"; 
	}
};

