#include "Plane.h"

Plane::Plane(): Vehicle() {}

Plane::Plane(int weight, float speed, float FuelConsumptionPerOneHundredKm) : Vehicle(weight, speed, FuelConsumptionPerOneHundredKm) {}

float Plane::FuelConsumption(float time) { return Vehicle::FuelConsumption(time); }

void Plane::Show() {
	std::cout << "Vehicle type: Plane" << std::endl;
	Vehicle::Show();
}