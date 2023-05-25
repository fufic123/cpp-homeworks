#include "Bike.h"

Bike::Bike() : Vehicle() {}

Bike::Bike(int weight, float speed, float FuelConsumptionPerOneHundredKm) : Vehicle(weight, speed, FuelConsumptionPerOneHundredKm) {}

float Bike::FuelConsumption(float time) { return Vehicle::FuelConsumption(time); }

void Bike::Show() {
	std::cout << "Vehicle type: Bike" << std::endl;
	Vehicle::Show();
}