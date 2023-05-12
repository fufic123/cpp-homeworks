#pragma once
#include <iostream>
#include "VideoCard.h"
#include "CPU.h"
#include "RAM.h"
#include "HDD.h"
using namespace std;

class LapTop{
	char* name = nullptr;
	VideoCard Videocard;
	CPU Cpu;
	RAM Ram;
	HDD Hdd;
	double price;
public:
	LapTop(const char* n, RAM& r, CPU& c, VideoCard& v, HDD& h, double p);
	LapTop(const LapTop& lp);
	~LapTop();

	void Print();

	const char* GetName()const;
	double GetPrice()const;

	void SetName(const char* n);
	void SetPrice(double pr);
};

LapTop::LapTop(const char* n, RAM& r, CPU& c, VideoCard& v, HDD& h, double p):Ram(r), Cpu(c), Videocard(v), HDD(h), price(p){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

LapTop::LapTop(const LapTop& lp):Ram(lp.Ram), Cpu(lp.Cpu), Videocard(lp.Videocard), Hdd(lp.HDD), price(lp.price){
	this->name = new char[strlen(lp.name) + 1];
	strcpy(this->name, lp.name);
}

LapTop::~LapTop(){
	delete[]name;
}

void LapTop::Print(){
	cout << "Name: " << name << "\n";
	cout << "RAM: " << Ram.GetName() << "\n";
	cout << "CPU: " << Cpu.GetName() << "\n";
	cout << "HDD: " << Hdd.GetName() << "\n";
	cout << "GPU: " << Videocard.GetName() << "\n";
	cout << "Price: " << price << "\n";
}

const char* LapTop::GetName()const{
	return name;
}

double LapTop::GetPrice()const{
	return price;
}

void LapTop::SetName(const char* n){
	if (name != nullptr) delete[] name;

	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

void LapTop::SetPrice(double p){
	price = p;
}