#include "Engine.h"

Engine::Engine(): power(0), torque(0), specificFuelConsumption(0) {}

Engine::Engine(int power, int torque, int specificFuelConsumption) : power(power), torque(torque), specificFuelConsumption(specificFuelConsumption) {}

void Engine::Show() { std::cout << "Power: " << power << " kW" << std::endl << "Torque: " << torque << " N*m" << std::endl << "Specific Fuel Consumption: " << specificFuelConsumption << " kW*h" << std::endl; }