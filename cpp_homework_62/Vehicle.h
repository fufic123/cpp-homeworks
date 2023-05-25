#pragma once
#include <iostream>

class Vehicle {
protected:
	int weight;
	float speed;
	float FuelConsumptionPerOneHundredKm;

public:
	Vehicle();
	Vehicle(int weight, float speed, float FuelConsumptionPerOneHundredKm);

	virtual float FuelConsumption(float time);
	virtual void Show();
};