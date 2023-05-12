#pragma once
#include <iostream>
using namespace std;

class HDD{
	char* name = nullptr;
	int memory;
	double price;
public:
	HDD(const HDD& h);
	HDD(const char* n);
	HDD(const char* n, int m);
	HDD(const char* n, int m, double r);
	~HDD();

	void Input();
	void Print();

	const char* GetName()const;
	const int GetMemory()const;
	double GetPrice()const;

	void SetName(const char* n);
	void SetPrice(double pr);
};

HDD::HDD(const HDD& h):memory(h.memory), price(h.price){
	this->name = new char[strlen(h.name) + 1];
	strcpy(this->name, h.name);
}


HDD::HDD(const char* n){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}


HDD::HDD(const char* n, int m):HDD(n){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}


HDD::HDD(const char* n, int m, double r):HDD(n, m){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	price = r;
}


HDD::~HDD(){
	delete[]name;
}


void HDD::Input(){
	char buff[20];
	cout << "Enter name -> ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy(this->name, buff);
	cout << "Enter price -> ";
	cin >> price;
}


void HDD::Print(){
	cout << "Name: " << name << "\n";
	cout << "Price: " << price << "\n";
	cout << "Memory: " << memory << "\n";
}


const char* HDD::GetName()const{
	return name;
}


const int HDD::GetMemory()const{
	return memory;
}


double HDD::GetPrice()const{
	return price;
}


void HDD::SetName(const char* n){
	if (name != nullptr) delete[] name;
	
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}


void HDD::SetPrice(double pr){
	price = pr;
}