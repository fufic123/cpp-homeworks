#pragma once
#include <iostream>
using namespace std;

class CPU{
	char* name = nullptr;
	double Ghz;
	double price;
public:
	CPU(const CPU& c);
	CPU(const char* n);
	CPU(const char* n, int m);
	CPU(const char* n, int m, double r);
  	~CPU();

	void Input();
	void Print();

	const char* GetName()const;
	const int GetGhz()const;
	double GetPrice()const;

	void SetName(const char* n);
	void SetGhz(double ghz);
	void SetPrice(double pr);
};

CPU::CPU(const CPU& c):Ghz(c.Ghz), price(c.price){
	this->name = new char[strlen(c.name) + 1];
	strcpy(this->name, c.name);
}

CPU::CPU(const char* n){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

CPU::CPU(const char* n, int m):CPU(n){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	Ghz = m;
}

CPU::CPU(const char* n, int m, double r):CPU(n, m){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	Ghz = m;
	price = r;
}

CPU::~CPU(){
	delete[]name;
}

void CPU::Input(){
	char buff[20];
	cout << "Enter name: ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy(this->name, buff);
	cout << "Enter price: ";
	cin >> price;
}

void CPU::Print(){
	cout << "Name: " << name << "\n";
	cout << "Price: " << price << "\n";
	cout << "Ghz: " << Ghz << "\n";
}

const char* CPU::GetName()const{
	return name;
}

const int CPU::GetGhz()const{
	return Ghz;
}

double CPU::GetPrice()const{
	return price;
}

void CPU::SetName(const char* n){
	if (name != nullptr) delete[] name;

	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

void CPU::SetGhz(double ghz){
	Ghz = ghz;
}

void CPU::SetPrice(double pr){
	price = pr;
}