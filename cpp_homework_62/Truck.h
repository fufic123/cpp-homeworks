#pragma once
#include <iostream>
#include "Vehicle.h"

class Truck : public Vehicle {
public:
	Truck();
	Truck(int weight, float speed, float FuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};