#pragma once
#include <iostream>

class Door {
protected:
	int height;
	int length;

public:
	Door();
	Door(int height, int length);

	void Show();
};