#pragma once
#include <iostream>
using namespace std;

class VideoCard{
	char* name = nullptr;
	int memory;
	double price;
public:
	VideoCard(const VideoCard& v);
	VideoCard(const char* n);
	VideoCard(const char* n, int m);
	VideoCard(const char* n, int m, double r);
	~VideoCard();

	void Input();
	void Print();

	const char* GetName()const;
	const int GetMemory()const;
	double GetPrice()const;

	void SetName(const char* n);
	void SetPrice(double pr);
};

VideoCard::VideoCard(const char* n){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

VideoCard::VideoCard(const char* n, int m):VideoCard(n){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

VideoCard::VideoCard(const char* n, int m, double r):VideoCard(n, m){
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	price = r;
}

VideoCard::VideoCard(const VideoCard& v):memory(v.memory), price(v.price){
	this->name = new char[strlen(v.name) + 1];
	strcpy(this->name, v.name);
}

VideoCard::~VideoCard(){
	delete[]name;
}

void VideoCard::Input(){
	char buff[20];
	cout << "Enter name: ";
	cin.getline(buff, 20);
	this->name = new char[strlen(buff) + 1];
	strcpy(this->name, buff);
	cout << "Enter price: ";
	cin >> price;
}

void VideoCard::Print(){
	cout << "Name: " << name << "\n";
	cout << "Price: " << price << "\n";
	cout << "Memory: " << memory << "\n";
}

const char* VideoCard::GetName()const{
	return name;
}

const int VideoCard::GetMemory()const{
	return memory;
}

double VideoCard::GetPrice()const{
	return price;
}

void VideoCard::SetName(const char* n){
	if (name != nullptr) delete[] name;

	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

void VideoCard::SetPrice(double pr){
	price = pr;
}