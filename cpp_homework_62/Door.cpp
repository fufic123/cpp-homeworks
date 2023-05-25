#include "Door.h"

Door::Door(): height(0), length(0) {}

Door::Door(int height, int length): height(height), length(length) {}

void Door::Show() { std::cout << "Height: " << height << "\"" << std::endl << "Length: " << length << "\"" << std::endl; }