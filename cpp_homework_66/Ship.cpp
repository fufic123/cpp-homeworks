#include "Ship.h"
#include <iostream>

Ship::Ship() {}

Ship::Ship(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats) : Vehicle(FuelConsumptionPerOneKm, Cost, Capacity, NumberOfSeats) {}

void Ship::Print() {
	std::cout.precision(10);
	std::cout << "Type: Ship" << std::endl
		<< "Fuel consumption per 1 Km: " << FuelConsumptionPerOneKm << " l/km" << std::endl
		<< "Cost: " << Cost << "$" << std::endl
		<< "Capacity: " << Capacity << " kg" << std::endl
		<< "Number of seats: " << NumberOfSeats << std::endl << std::endl;
}

void Ship::Init() {
	std::cout << "Type: Ship" << std::endl;
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

float Ship::FuelConsumption(float Distance) { return Distance * FuelConsumptionPerOneKm; }

float Ship::GetCost() { return Cost; }
void Ship::SetCost(float Cost) { this->Cost = Cost; }

float Ship::GetCapacity() { return Capacity; }
void Ship::SetCapacity(float Capacity) { this->Capacity = Capacity; }

int Ship::GetNumberOfSeats() { return NumberOfSeats; }
void Ship::SetNumberOfSeats(int NumberOfSeats) { this->NumberOfSeats = NumberOfSeats; }