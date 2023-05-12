#pragma once
#include <iostream>
using namespace std;

class RAM{
	char* name = nullptr;
	int memory;
	double price;
public:
	RAM(const RAM& r);
	RAM(const char* n);
	RAM(const char* n, int m);
	RAM(const char* n, int m, double r);
	~RAM();

	void Input();
	void Print();

	const char* GetName()const;
	const int GetMemory()const;
	double GetPrice()const;

	void SetName(const char* n);
	void SetPrice(double pr);
};

RAM::RAM(const char* n) {
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

RAM::RAM(const char* n, int m):RAM(n){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

RAM::RAM(const char* n, int m, double r):RAM(n, m){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	price = r;
}

RAM::RAM(const RAM& r):memory(r.memory), price(r.price){
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
}

RAM::~RAM(){
	delete[]name;
}

void RAM::Input(){
	char buff[20];
	cout << "Enter name: ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy(this->name, buff);
	cout << "Enter price: ";
	cin >> price;
}

void RAM::Print(){
	cout << "Name: " << name << "\n";
	cout << "Price: " << price << "\n";
	cout << "Memory: " << memory << "\n";
}

const char* RAM::GetName()const{
	return name;
}

const int RAM::GetMemory()const{
	return memory;
}

double RAM::GetPrice()const{
	return price;
}

void RAM::SetName(const char* n){
	if (name != nullptr) delete[] name;

	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

void RAM::SetPrice(double pr){
	price = pr;
}