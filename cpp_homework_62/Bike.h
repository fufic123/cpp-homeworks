#pragma once
#include <iostream>
#include "Vehicle.h"

class Bike : public Vehicle {
public:
	Bike();
	Bike(int weight, float speed, float FuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};