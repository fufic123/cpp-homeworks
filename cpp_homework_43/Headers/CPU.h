#pragma once
#include <iostream>
using namespace std;

class CPU {
private:
  char *name;
  double ghz;
  double price;

public:
  CPU(const CPU &copy);
  CPU(const char *name, double ghz, double price);
  ~CPU();

  void Input();
  void Print();

  const char *GetName();
  double GetGhz();
  double GetPrice();

  void SetName(const char *name);
  void Setghz(double ghz);
  void SetPrice(double price);
};

CPU::CPU(const CPU &copy) : ghz(copy.ghz), price(copy.price) {
  name = new char[strlen(copy.name) + 1];
  strcpy(name, copy.name);
}

CPU::CPU(const char *name, double ghz, double price) : ghz(ghz), price(price) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

CPU::~CPU() {
  delete[] name;
}

void CPU::Input() {
  char buff[20];
  cout << "Enter name: ";
  cin.getline(buff, 20);
  this->name = new char[strlen(buff) + 1];
  strcpy(this->name, buff);

  cout << "Enter ghz: ";
  cin >> ghz;

  cout << "Enter price: ";
  cin >> price;
}

void CPU::Print() {
  cout << "\tName: " << name << "\n";
  cout << "\tGhz: " << ghz << "\n";
  cout << "\tPrice: " << price << "\n\n";
}

const char *CPU::GetName() {
  return name;
}
double CPU::GetGhz() {
  return ghz;
}
double CPU::GetPrice()
{
  return price;
}

void CPU::SetName(const char *name) {
  if (name != nullptr)
    delete[] name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}
void CPU::Setghz(double ghz) {
  this->ghz = ghz;
}
void CPU::SetPrice(double price) {
  this->price = price;
}