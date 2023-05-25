#include "Truck.h"

Truck::Truck() : Vehicle() {}

Truck::Truck(int weight, float speed, float FuelConsumptionPerOneHundredKm) : Vehicle(weight, speed, FuelConsumptionPerOneHundredKm) {}

float Truck::FuelConsumption(float time) { return Vehicle::FuelConsumption(time); }

void Truck::Show() {
	std::cout << "Vehicle type: Truck" << std::endl;
	Vehicle::Show();
}