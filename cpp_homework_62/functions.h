#pragma once
#include "includes.h"

int menu() {
	system("cls");
	int choice;
	std::cout
		<< "---------------------" << std::endl
		<< "What you want to do?" << std::endl
		<< "1. Add a new vehicle" << std::endl
		<< "2. Delete a vehicle" << std::endl
		<< "3. Show all vehicles" << std::endl
		<< "4. Exit" << std::endl
		<< "---------------------" << std::endl
		<< ">>> ";
	std::cin >> choice;
	if (choice < 1 || choice > 4) {
		system("cls");
		menu();
	}
	return choice;
}

void add(std::vector<Vehicle*>& v) {
ADD:
	system("cls");
	int choice;

	std::cout
		<< "---------------------" << std::endl
		<< "What type of vehicle you want to add?" << std::endl
		<< "1. Plane" << std::endl
		<< "2. Ship" << std::endl
		<< "3. Truck" << std::endl
		<< "4. Bike" << std::endl
		<< "5. Automobile" << std::endl
		<< "6. Return" << std::endl
		<< "---------------------" << std::endl
		<< ">>> ";

	std::cin >> choice;

	if (choice < 1 || choice > 6) goto ADD;

	else if (choice == 1) {
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;

		system("cls");
		std::cout << "---------------------" << std::endl << "Enter data of the plane" << std::endl << "---------------------" << std::endl;
		std::cout << "Weight >>> ";
		std::cin >> weight;
		std::cout << "Speed >>> ";
		std::cin >> speed;
		std::cout << "Fuel consumption per 100 km >>> ";
		std::cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Plane(weight, speed, FuelConsumptionPerOneHundredKm));
	}

	else if (choice == 2) {
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;

		system("cls");
		std::cout << "---------------------" << std::endl << "Enter data of the ship" << std::endl << "---------------------" << std::endl;
		std::cout << "Weight >>> ";
		std::cin >> weight;
		std::cout << "Speed >>> ";
		std::cin >> speed;
		std::cout << "Fuel consumption per 100 km >>> ";
		std::cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Ship(weight, speed, FuelConsumptionPerOneHundredKm));
	}

	else if (choice == 3) {
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;

		system("cls");
		std::cout << "---------------------" << std::endl << "Enter data of the truck" << std::endl << "---------------------" << std::endl;
		std::cout << "Weight >>> ";
		std::cin >> weight;
		std::cout << "Speed >>> ";
		std::cin >> speed;
		std::cout << "Fuel consumption per 100 km >>> ";
		std::cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Truck(weight, speed, FuelConsumptionPerOneHundredKm));
	}

	else if (choice == 4) {
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;

		system("cls");
		std::cout << "---------------------" << std::endl << "Enter data of the bike" << std::endl << "---------------------" << std::endl;
		std::cout << "Weight >>> ";
		std::cin >> weight;
		std::cout << "Speed >>> ";
		std::cin >> speed;
		std::cout << "Fuel consumption per 100 km >>> ";
		std::cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Bike(weight, speed, FuelConsumptionPerOneHundredKm));
	}

	else if (choice == 5) {
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;
		system("cls");
		std::cout << "---------------------" << std::endl << "Enter data of the automobile" << std::endl << "---------------------" << std::endl;
		std::cout << "Weight >>> ";
		std::cin >> weight;
		std::cout << "Speed >>> ";
		std::cin >> speed;
		std::cout << "Fuel consumption per 100 km >>> ";
		std::cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Automobile(weight, speed, FuelConsumptionPerOneHundredKm));
	}

	else return;
}

void del(std::vector<Vehicle*>& v) {
DEL:
	system("cls");
	int choice;
	std::cout
		<< "----------------------------------------------------------" << std::endl
		<< "Which element do you want to delete? (Enter a number only)" << std::endl
		<< "----------------------------------------------------------" << std::endl;
	for (int i = 0; i < v.size(); i++) {
		std::cout << i + 1 << ". ";
		v[i]->Show();
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << "To return enter 0 >>> ";

	std::cin >> choice;
	if (choice == 0) return;
	else if (choice < 0 || choice > v.size()) goto DEL;
	else {
		v.erase(v.begin() + choice - 1);
		return;
	}
}

void show(std::vector<Vehicle*> v) {
	system("cls");
	char symbol;

	std::cout << "---------------------" << std::endl;
	for (int i = 0; i < v.size(); i++) {
		std::cout << i + 1 << ". ";
		v[i]->Show();
		std::cout << "---------------------" << std::endl;
	}
	std::cout << "To return enter r or R >>> ";

SYMBOL:
	std::cin >> symbol;
	if (symbol == 'r' || symbol == 'R') return;
	else goto SYMBOL;
}