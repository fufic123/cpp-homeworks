#pragma once
#include <iostream>
#include "Vehicle.h"

class Plane: public Vehicle {
public:
	Plane();
	Plane(int weight, float speed, float FuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};