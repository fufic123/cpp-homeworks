#pragma once
#include <iostream>
using namespace std;

class HDD {
private:
  char *name;
  const int memory;
  double price;

public:
  HDD(const HDD &copy);
  HDD(const char *name, int memory, double price);
  ~HDD();

  void Input();
  void Print();
  const char *GetName();
  const int GetMemory();
  double GetPrice();

  void SetName(const char *name);
  void SetPrice(double price);
};

HDD::HDD(const HDD &copy) : memory(copy.memory), price(copy.price) {
  name = new char[strlen(copy.name) + 1];
  strcpy(name, copy.name);
}

HDD::HDD(const char *name, int memory, double price) : memory(memory), price(price) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

HDD::~HDD() {
  delete[] name;
}

void HDD::Input() {
  char buff[20];
  cout << "Enter name: ";
  cin.getline(buff, 20);
  this->name = new char[strlen(buff) + 1];
  strcpy(this->name, buff);
  cout << "Enter price: ";
  cin >> price;
}

void HDD::Print() {
  cout << "\tName: " << name << "\n";
  cout << "\tMemory: " << memory << "\n";
  cout << "\tPrice: " << price << "\n\n";
}

const char *HDD::GetName() {
  return name;
}
const int HDD::GetMemory() {
  return memory;
}
double HDD::GetPrice() {
  return price;
}

void HDD::SetName(const char *name) {
  if (name != nullptr)
    delete[] name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}
void HDD::SetPrice(double price) {
  this->price = price;
}