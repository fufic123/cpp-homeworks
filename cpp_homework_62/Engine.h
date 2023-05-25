#pragma once
#include <iostream>

class Engine {
protected:
	int power;
	int torque;
	int specificFuelConsumption;

public:
	Engine();
	Engine(int power, int torque, int specificFuelConsumption);

	void Show();
};