#include "includes.h"
#include "functions.h"

int main() {
	Car c(4, 4, 15, "Fronway", 40, 4000, 20, 50, 35);
	c.Show();
	Sleep(5000);

	int choice;
	std::vector<Vehicle*> vehicle(0);
	do {
		choice = menu();
		if (choice == 1) add(vehicle); 
		if (choice == 2) del(vehicle);
		if (choice == 3) show(vehicle);
	} while (choice != 4);
}