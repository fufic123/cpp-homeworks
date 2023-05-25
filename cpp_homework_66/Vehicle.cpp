#include "Vehicle.h"

Vehicle::Vehicle(): FuelConsumptionPerOneKm(0), Cost(0), Capacity(0), NumberOfSeats(0) {}

Vehicle::Vehicle(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats) : FuelConsumptionPerOneKm(FuelConsumptionPerOneKm), Cost(Cost), Capacity(Capacity), NumberOfSeats(NumberOfSeats) {}