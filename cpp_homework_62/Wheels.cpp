#include "Wheels.h"

Wheels::Wheels(): diameter(0), firm("") {}

Wheels::Wheels(float diameter, std::string firm): diameter(diameter), firm(firm) {}

void Wheels::Show() { std::cout << "Diamemet: " << diameter << "\"" << std::endl << "Firm: " << firm << std::endl; }