#include "Car.h"

Car::Car(): numberOfDoors(0), numberOfWheels(0) {}

Car::Car(int numberOfDoors, int numberOfWheels, float diameter, std::string firm, int power, int torque, int specificFuelConsumption, int height, int length):
	numberOfDoors(numberOfDoors), numberOfWheels(numberOfWheels), Wheels(diameter, firm), Engine(power, torque, specificFuelConsumption), Door(height, length) {}

void Car::Show() {
	std::cout << "Wheels: " << std::endl << "Number of wheels: " << numberOfWheels << std::endl;
	Wheels::Show();
	std::cout << "Engine: " << std::endl;
	Engine::Show();
	std::cout << "Doors: " << std::endl << "Number of doors: " << numberOfDoors << std::endl;
	Door::Show();
}