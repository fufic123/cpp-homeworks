#include <iostream>
#include "Headers/Laptop.h"
using namespace std;

int main() {
	Laptop laptop;
	laptop.Show();
	cout << "\n";

	Mouse mouse("Bloody");
	Printer printer("Canon", "black");
	Webcam webcam("Logitech", "1080p");

	Laptop* laptop2 = new Laptop("Intel", 3.2, "Nvidia GeForce", 3060, "Kingston", 8, &mouse, &printer, &webcam);
	laptop2->Show();
	delete laptop2;
	cout << "\n";
}