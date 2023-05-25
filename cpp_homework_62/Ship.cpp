#include "Ship.h"

Ship::Ship() : Vehicle() {}

Ship::Ship(int weight, float speed, float FuelConsumptionPerOneHundredKm) : Vehicle(weight, speed, FuelConsumptionPerOneHundredKm) {}

float Ship::FuelConsumption(float time) { return Vehicle::FuelConsumption(time); }

void Ship::Show() {
	std::cout << "Vehicle type: Ship" << std::endl;
	Vehicle::Show();
}