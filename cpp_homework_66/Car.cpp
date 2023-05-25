#include "Car.h"
#include <iostream>

Car::Car() {}

Car::Car(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats) : Vehicle(FuelConsumptionPerOneKm, Cost, Capacity, NumberOfSeats) {}

void Car::Print() {
	std::cout << "Type: Car" << std::endl 
		<< "Fuel consumption per 1 Km: " << FuelConsumptionPerOneKm << " l/km" << std::endl
		<< "Cost: " << Cost << "$" << std::endl
		<< "Capacity: " << Capacity << " kg" << std::endl
		<< "Number of seats: " << NumberOfSeats << std::endl << std::endl;
}

void Car::Init() {
	std::cout << "Type: Car" << std::endl;
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

float Car::FuelConsumption(float Distance) { return Distance * FuelConsumptionPerOneKm; }

float Car::GetCost() { return Cost; }
void Car::SetCost(float Cost) { this->Cost = Cost; }

float Car::GetCapacity() { return Capacity; }
void Car::SetCapacity(float Capacity) { this->Capacity = Capacity; }

int Car::GetNumberOfSeats() { return NumberOfSeats; }
void Car::SetNumberOfSeats(int NumberOfSeats) { this->NumberOfSeats = NumberOfSeats; }