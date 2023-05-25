#pragma once
#include <iostream>
#include "Vehicle.h"

class Ship : public Vehicle {
public:
	Ship();
	Ship(int weight, float speed, float FuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};