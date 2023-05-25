#pragma once
#include "Vehicle.h"

class Ship : public Vehicle {
public:
	Ship();
	Ship(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats);

	void Print();
	void Init();

	float FuelConsumption(float Distance);

	float GetCost();
	void SetCost(float Cost);

	float GetCapacity();
	void SetCapacity(float Capacity);

	int GetNumberOfSeats();
	void SetNumberOfSeats(int NumberOfSeats);
};