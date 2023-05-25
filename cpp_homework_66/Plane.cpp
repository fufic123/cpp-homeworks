#include "Plane.h"
#include <iostream>

Plane::Plane() {}

Plane::Plane(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats) : Vehicle(FuelConsumptionPerOneKm, Cost, Capacity, NumberOfSeats) {}

void Plane::Print() {
	std::cout.precision(10);
	std::cout << "Type: Plane" << std::endl
		<< "Fuel consumption per 1 Km: " << FuelConsumptionPerOneKm << " l/km" << std::endl
		<< "Cost: " << Cost << "$" << std::endl
		<< "Capacity: " << Capacity << " kg" << std::endl
		<< "Number of seats: " << NumberOfSeats << std::endl << std::endl;
}

void Plane::Init() {
	std::cout << "Type: Plane" << std::endl;
	std::cout << "Enter fuel consumption per 1 Km >> ";
	std::cin >> FuelConsumptionPerOneKm;
	std::cout << "Enter cost >> ";
	std::cin >> Cost;
	std::cout << "Enter capacity >> ";
	std::cin >> Capacity;
	std::cout << "Enter number of seats >> ";
	std::cin >> NumberOfSeats;
	std::cout << std::endl;
}

float Plane::FuelConsumption(float Distance) { return Distance * FuelConsumptionPerOneKm; }

float Plane::GetCost() { return Cost; }
void Plane::SetCost(float Cost) { this->Cost = Cost; }

float Plane::GetCapacity() { return Capacity; }
void Plane::SetCapacity(float Capacity) { this->Capacity = Capacity; }

int Plane::GetNumberOfSeats() { return NumberOfSeats; }
void Plane::SetNumberOfSeats(int NumberOfSeats) { this->NumberOfSeats = NumberOfSeats; }