#pragma once
#include <iostream>
#include "Wheels.h"
#include "Engine.h"
#include "Door.h"
#include "Vehicle.h"

class Car: protected Wheels, protected Engine, protected Door, protected Vehicle {
protected:
	int numberOfDoors;
	int numberOfWheels;

public:
	Car();
	Car(int numberOfDoors, int numberOfWheels, float diameter, std::string firm, int power, int torque, int specificFuelConsumption, int height, int length);

	void Show();
};