#include <iostream>
#include "CPU.h"
#include "VideoCard.h"
#include "RAM.h"
#include "Mouse.h"
#include "Printer.h"
#include "Webcam.h"

using namespace std;

class Laptop {
private:
	CPU cp;
	VideoCard vc;
	RAM ram;
	Mouse* mouse;
	Printer* printer;
	Webcam* webcam;

public:
	Laptop() {
		CPU cp("", 0.0);
		this->cp = cp;

		VideoCard vc("", 0);
		this->vc = vc;

		RAM ram("", 0);
		this->ram = ram;

		Mouse* mouse = new Mouse("");
		this->mouse = mouse;

		Printer* printer = new Printer("", 0);
		this->printer = printer;

		Webcam* webcam = new Webcam("", "");
		this->webcam = webcam;
	}

	Laptop(
		string cpu,
		float ghz, 
		string videocard, 
		int number, 
		string ramName, 
		int memory, 
		Mouse* mouse, 
		Printer* printer, 
		Webcam* webcam)
	{
		CPU cp(cpu, ghz);
		VideoCard vc(videocard, number);
		RAM ram(ramName, memory);

		this->cp = cp;
		this->vc = vc;
		this->ram = ram;
		this->mouse = mouse;
		this->printer = printer;
		this->webcam = webcam;
	}

	void Show() {
		cout << "CPU: " << "\n";
		cp.Show();
		cout << "GPU: " << "\n";
		vc.Show();
		cout << "RAM: " << "\n";
		ram.Show();
		cout << "Mouse: " << "\n";
		mouse->Show();
		cout << "Printer: " << "\n";
		printer->Show();
		cout << "Webcam: " << "\n";
		webcam->Show();
	}
};
