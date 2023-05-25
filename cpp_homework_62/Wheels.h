#pragma once
#include <iostream>

class Wheels {
protected:
	float diameter;
	std::string firm;

public:
	Wheels();
	Wheels(float diameter, std::string firm);

	void Show();
};