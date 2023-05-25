#include "Automobile.h"

Automobile::Automobile() : Vehicle() {}

Automobile::Automobile(int weight, float speed, float FuelConsumptionPerOneHundredKm) : Vehicle(weight, speed, FuelConsumptionPerOneHundredKm) {}

float Automobile::FuelConsumption(float time) { return Vehicle::FuelConsumption(time); }

void Automobile::Show() {
	std::cout << "Vehicle type: Automobile" << std::endl;
	Vehicle::Show();
}