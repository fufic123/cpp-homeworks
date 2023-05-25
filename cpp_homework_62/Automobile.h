#pragma once
#include <iostream>
#include "Vehicle.h"

class Automobile : public Vehicle {
public:
	Automobile();
	Automobile(int weight, float speed, float FuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};