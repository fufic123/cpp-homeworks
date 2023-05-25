#include "includes.h"

int main() {
	Vehicle* vehicle[3] = {new Car(0.14, 10000, 700, 4), new Plane(7.5, 10000000, 120000, 155), new Ship(3.5, 1000000, 50000, 75)};
	for (int i = 0; i < 3; i++) vehicle[i]->Print();
	for (int i = 0; i < 3; i++) vehicle[i]->Init();
	for (int i = 0; i < 3; i++) vehicle[i]->Print();
	for (int i = 0; i < 3; i++) {
		float distance;
		std::cout << "Enter distance >> ";
		std::cin >> distance;
		std::cout << "Fuel consumption: " << vehicle[i]->FuelConsumption(distance) << std::endl;
	}
	for (int i = 0; i < 3; i++) delete vehicle[i];
}